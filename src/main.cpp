/*
   MIT License

  Copyright (c) 2025 Felix Biego

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  ______________  _____
  ___  __/___  /_ ___(_)_____ _______ _______
  __  /_  __  __ \__  / _  _ \__  __ `/_  __ \
  _  __/  _  /_/ /_  /  /  __/_  /_/ / / /_/ /
  /_/     /_.___/ /_/   \___/ _\__, /  \____/
                              /____/

*/

#include <Arduino.h>

#include "main.h"
#include "ui.h"

#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <ESP32Time.h>
#include <ArduinoJson.h>

WiFiMulti wifiMulti;
ESP32Time rtc(3600 * 3);

uint8_t lv_buffer[2][LV_BUFFER_SIZE];

#define LVGL_LOCK() xSemaphoreTakeRecursive(lvgl_mutex, portMAX_DELAY)
#define LVGL_UNLOCK() xSemaphoreGiveRecursive(lvgl_mutex)

// Locking LVGL calls to prevent concurrent access
// This is important because LVGL is not thread-safe
// and we need to ensure that only one task is accessing it at a time
// This is done using a recursive mutex
#define LVGL_EXEC(code) \
  do                    \
  {                     \
    if (LVGL_LOCK())    \
    {                   \
      code;             \
      LVGL_UNLOCK();    \
    }                   \
  } while (0)

SemaphoreHandle_t lvgl_mutex; // Global mutex for LVGL

bool active_request = false;
bool active_connect = false;

int total_issues = 0;

String user = "lvgl";
String repo = "lvgl";

lv_obj_t *stats_arc;
lv_obj_t *stats2_arc;
lv_obj_t *stats3_arc;
lv_obj_t *stats4_arc;

bool run_request();

lv_display_rotation_t get_rotation(uint8_t rotation)
{
  if (rotation > 3)
    return LV_DISPLAY_ROTATION_0;
  return (lv_display_rotation_t)rotation;
}

/* Display flushing */
void my_disp_flush(lv_display_t *display, const lv_area_t *area, unsigned char *data)
{

  uint32_t w = lv_area_get_width(area);
  uint32_t h = lv_area_get_height(area);

#ifdef SW_ROTATION
  lv_display_rotation_t rotation = lv_display_get_rotation(display);
  lv_area_t rotated_area;
  if (rotation != LV_DISPLAY_ROTATION_0)
  {
    lv_color_format_t cf = lv_display_get_color_format(display);
    /*Calculate the position of the rotated area*/
    rotated_area = *area;
    lv_display_rotate_area(display, &rotated_area);
    /*Calculate the source stride (bytes in a line) from the width of the area*/
    uint32_t src_stride = lv_draw_buf_width_to_stride(lv_area_get_width(area), cf);
    /*Calculate the stride of the destination (rotated) area too*/
    uint32_t dest_stride = lv_draw_buf_width_to_stride(lv_area_get_width(&rotated_area), cf);
    /*Have a buffer to store the rotated area and perform the rotation*/
    static uint8_t rotated_buf[LV_BUFFER_SIZE];
    lv_draw_sw_rotate(data, rotated_buf, w, h, src_stride, dest_stride, rotation, cf);
    /*Use the rotated area and rotated buffer from now on*/
    area = &rotated_area;
    data = rotated_buf;
  }
#endif

  if (tft.getStartCount() == 0)
  {
    tft.endWrite();
  }

  tft.pushImageDMA(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (uint16_t *)data);
  lv_display_flush_ready(display); /* tell lvgl that flushing is done */
}

void rounder_event_cb(lv_event_t *e)
{
  lv_area_t *area = lv_event_get_invalidated_area(e);
  uint16_t x1 = area->x1;
  uint16_t x2 = area->x2;

  uint16_t y1 = area->y1;
  uint16_t y2 = area->y2;

  // round the start of coordinate down to the nearest 2M number
  area->x1 = (x1 >> 1) << 1;
  area->y1 = (y1 >> 1) << 1;
  // round the end of coordinate up to the nearest 2N+1 number
  area->x2 = ((x2 >> 1) << 1) + 1;
  area->y2 = ((y2 >> 1) << 1) + 1;
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_t *indev_driver, lv_indev_data_t *data)
{
  uint16_t touchX, touchY;
  bool touched = tft.getTouch(&touchX, &touchY);

  if (!touched)
  {
    data->state = LV_INDEV_STATE_RELEASED;
  }
  else
  {
    data->state = LV_INDEV_STATE_PRESSED;
    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;
  }
}

bool updateTime()
{
  bool state = false;
  HTTPClient http;
  http.begin("https://iot.fbiego.com/api/v1/time");
  int httpCode = http.GET();
  String payload = http.getString();
  Serial.println(payload);
  if (httpCode == HTTP_CODE_OK)
  {
    JsonDocument json;
    deserializeJson(json, payload);
    rtc.setTime(json["timestamp"].as<unsigned long>());
    state = true;
  }
  http.end();

  return state;
}

void getRepoInfo()
{
  HTTPClient http;
  http.begin("https://api.github.com/repos/" + user + "/" + repo);
  int httpCode = http.GET();
  String payload = http.getString();
  Serial.println(payload);
  if (httpCode == HTTP_CODE_OK)
  {
    JsonDocument json;
    deserializeJson(json, payload);

    LVGL_EXEC({
      lv_subject_copy_string(&subject_name, json["name"].as<String>().c_str());
      lv_subject_set_int(&subject_stars, json["stargazers_count"].as<int>());
    });
    total_issues = json["open_issues_count"].as<int>();
  }
  http.end();
}

void getIssueInfo()
{
  HTTPClient http;
  http.begin("https://api.github.com/search/issues?q=repo:" + user + "/" + repo + "%20is:issue%20is:open");
  int httpCode = http.GET();
  // String payload = http.getString(); // fails if response is too long
  WiFiClient *stream = http.getStreamPtr();
  String payload = "";
  bool w = false;
  while (stream->available())
  {
    char c = stream->read();
    if (c == '{')
      w = true; // detect start of json
    if (w && c == ',')
    {
      payload += '}'; // break on first comma and close json
      break;
    }
    if (w)
      payload += c;
  }
  Serial.println(payload);
  if (httpCode == HTTP_CODE_OK)
  {
    JsonDocument json;
    deserializeJson(json, payload);

    int issues = json["total_count"].as<int>();
    LVGL_EXEC({
      lv_subject_set_int(&subject_issues, issues);
      lv_subject_set_int(&subject_prs, total_issues - issues);

      if (stats_arc)
      {
        lv_arc_set_range(stats_arc, 0, total_issues);
      }
      if (stats2_arc)
      {
        lv_arc_set_range(stats2_arc, 0, total_issues);
      }
      if (stats3_arc)
      {
        lv_arc_set_range(stats3_arc, 0, total_issues);
      }
      if (stats4_arc)
      {
        lv_arc_set_range(stats4_arc, 0, total_issues);
      }
    });
  }
  http.end();
}

void gesture_events_cb(lv_event_t *e)
{
  lv_obj_t * screen = (lv_obj_t *)lv_event_get_user_data(e);
  if (screen)
  {
    lv_screen_load(screen);
  }
}

void update_task(void *p)
{

  Serial.println("Fetching data");
  if (!updateTime())
  {
    updateTime();
  }

  getRepoInfo();
  getIssueInfo();

  active_request = false;

  vTaskDelete(NULL);
}

void connect_task(void *p)
{
  uint8_t status;

  LVGL_EXEC({
    lv_subject_copy_string(&subject_name, "Connecting...");
  });
  while (true)
  {
    status = wifiMulti.run();
    // Serial.printf("WiFi trying: %d\n", status);
    if (status == WL_CONNECTED) // || status == WL_CONNECT_FAILED || status == WL_DISCONNECTED || status == WL_NO_SSID_AVAIL)
    {
      break;
    }
    delay(100);
  }

  Serial.printf("WiFi exit: %d\n", status);
  String info;
  switch (status)
  {
  case WL_CONNECTED:
    info = WiFi.SSID();
    break;
  case WL_CONNECT_FAILED:
    info = "Failed";
    break;
  case WL_NO_SSID_AVAIL:
    info = "N/A";
    break;
  case WL_DISCONNECTED:
    info = "Disconnected";
    break;
  default:
    info = "Error " + String(status);
  }
  Serial.println(info);

  LVGL_EXEC({
    lv_subject_copy_string(&subject_name, info.c_str());
  });

  if (status == WL_CONNECTED)
  {
    run_request();
  }

  active_connect = false;

  vTaskDelete(NULL);
}

bool run_request()
{
  // returns true if the task was created
  // returns false if the previous task has not completed, new one cannot be created
  if (!active_request)
  {
    active_request = true;
    xTaskCreate(
        update_task,     // Function that should be called
        "HTTP Requests", // Name of the task (for debugging)
        8192,            // Stack size (bytes)
        NULL,            // Parameter to pass
        1,               // Task priority
        NULL
    );

    return true;
  }
  else
  {
    return false;
  }
}

bool run_connect()
{

  if (!active_connect)
  {
    active_connect = true;
    xTaskCreate(
        connect_task,   // Function that should be called
        "WIFI Connect", // Name of the task (for debugging)
        4096,           // Stack size (bytes)
        NULL,           // Parameter to pass
        1,              // Task priority
        NULL);
    return true;
  }
  else
  {
    return false;
  }
}

static uint32_t my_tick(void)
{
  return millis();
}

void setup()
{

#ifdef ELECROW_C3
  elecrow_c3_init();
#endif

  Serial.begin(115200);

  tft.init();
  tft.initDMA();
  tft.startWrite();
  tft.fillScreen(0x0000);

  lvgl_mutex = xSemaphoreCreateMutex(); // Create the mutex

  lv_init();

  lv_tick_set_cb(my_tick);

  static lv_display_t *lv_display = lv_display_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  lv_display_set_color_format(lv_display, LV_COLOR_FORMAT_RGB565_SWAPPED);
  lv_display_set_flush_cb(lv_display, my_disp_flush);
  lv_display_set_buffers(lv_display, lv_buffer[0], lv_buffer[1], LV_BUFFER_SIZE, LV_DISPLAY_RENDER_MODE_PARTIAL);
  lv_display_add_event_cb(lv_display, rounder_event_cb, LV_EVENT_INVALIDATE_AREA, NULL);

  static lv_indev_t *lv_input = lv_indev_create();
  lv_indev_set_type(lv_input, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(lv_input, my_touchpad_read);

  lv_obj_t *label = lv_label_create(lv_screen_active());
  lv_label_set_text(label, "Hello LVGL!");
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

  ui_init("");

  lv_obj_t *screen1 = main_create();
  lv_obj_t *screen2 = screen2_create();
  lv_obj_t *screen3 = screen3_create();
  lv_obj_t *screen4 = screen4_create();
  lv_obj_t *selector = selector_create();

  lv_obj_add_event_cb(screen1, gesture_events_cb, LV_EVENT_LONG_PRESSED, selector);
  lv_obj_add_event_cb(screen2, gesture_events_cb, LV_EVENT_LONG_PRESSED, selector);
  lv_obj_add_event_cb(screen3, gesture_events_cb, LV_EVENT_LONG_PRESSED, selector);
  lv_obj_add_event_cb(screen4, gesture_events_cb, LV_EVENT_LONG_PRESSED, selector);

  item_create(selector, main_preview, screen1);
  item_create(selector, screen2_preview, screen2);
  item_create(selector, screen3_preview, screen3);
  item_create(selector, screen4_preview, screen4);

  stats_arc = lv_obj_find_by_name(screen1, "stats_arc");
  stats2_arc = lv_obj_find_by_name(screen2, "stats_arc");
  stats3_arc = lv_obj_find_by_name(screen3, "stats_arc");
  stats4_arc = lv_obj_find_by_name(screen4, "stats_arc");

  lv_screen_load(screen1);

  WiFi.mode(WIFI_STA);
  wifiMulti.addAP("WIFI_NAME", "WIFI_PASSWORD");

  lv_subject_set_int(&subject_issues, 0);
  lv_subject_set_int(&subject_prs, 0);
  lv_subject_set_int(&subject_stars, 0);
  lv_subject_copy_string(&subject_name, "Connecting...");

  run_connect();
}

static int lastHour = -1;

void loop()
{

  LVGL_EXEC({
    lv_timer_handler(); // Update the UI-
    delay(5);

    lv_subject_copy_string(&subject_time, rtc.getTime("%H:%M").c_str());
    lv_subject_copy_string(&subject_date, rtc.getTime("%a %d").c_str());
    lv_subject_set_int(&subject_wifi, WiFi.status() == WL_CONNECTED ? 1 : 0);
  });

  int hour = rtc.getHour(true);
  int minute = rtc.getMinute();
  int sec = rtc.getSecond();

  if (WiFi.status() == WL_CONNECTED)
  {
    // Run only once each hour
    if (hour != lastHour && minute == 0 && sec < 5)
    {
      lastHour = hour;

      run_request();
    }
  }
}
