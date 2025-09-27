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

int total_issues = 0;

lv_obj_t *stats_arc;

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
    DynamicJsonDocument json(512);
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
  http.begin("https://api.github.com/repos/lvgl/lvgl");
  int httpCode = http.GET();
  String payload = http.getString();
  Serial.println(payload);
  if (httpCode == HTTP_CODE_OK)
  {
    JsonDocument json;
    deserializeJson(json, payload);

    lv_subject_copy_string(&subject_name, json["full_name"].as<String>().c_str());
    lv_subject_set_int(&subject_stars, json["stargazers_count"].as<int>());
    total_issues = json["open_issues_count"].as<int>();

  }
  http.end();

}

void getIssueInfo()
{
  HTTPClient http;
  http.begin("https://api.github.com/search/issues?q=repo:lvgl/lvgl%20is:issue%20is:open");
  int httpCode = http.GET();
  String payload = http.getString();
  Serial.println(payload);
  if (httpCode == HTTP_CODE_OK)
  {
    JsonDocument json;
    deserializeJson(json, payload);

    int issues = json["total_count"].as<int>();
    lv_subject_set_int(&subject_issues, issues);
    lv_subject_set_int(&subject_prs, total_issues - issues);

    if (stats_arc) {
      lv_arc_set_range(stats_arc, 0, total_issues);
      lv_arc_set_value(stats_arc, issues);
    }

  }
  http.end();

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

  tft.init();
  tft.initDMA();
  tft.startWrite();
  tft.fillScreen(0x0000);

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
  lv_label_set_text(label, "Hello LVGL!" );
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0 );

  ui_init("");

  lv_obj_t *main = main_create();

  stats_arc = lv_obj_find_by_name(main, "stats_arc");
  lv_screen_load(main);

  WiFi.mode(WIFI_STA);
  wifiMulti.addAP("WIFI", "PASSWORD");

  int tries;
  while (wifiMulti.run() != WL_CONNECTED)
  {
    delay(100);
    tries++;
    if (tries > 1000)
    {
      ESP.restart();
    }
  }

  if (!updateTime())
  {
    updateTime();
  }

  getRepoInfo();

  getIssueInfo();
  

}

void loop()
{
  lv_timer_handler(); // Update the UI-
  delay(5);

  lv_subject_copy_string(&subject_time, rtc.getTime("%H:%M").c_str());
  lv_subject_copy_string(&subject_date, rtc.getTime("%a %d").c_str());

  lv_subject_set_int(&subject_wifi, WiFi.status() == WL_CONNECTED ? 1 : 0);


}
