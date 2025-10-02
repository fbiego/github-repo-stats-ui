/**
 * @file item_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "item_gen.h"
#include "stats_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * item_create(lv_obj_t * parent, const void * preview, void * screen)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_pad_all(&style_main, 0);
        lv_style_set_width(&style_main, 200);
        lv_style_set_height(&style_main, 200);
        lv_style_set_radius(&style_main, 100);
        lv_style_set_bg_opa(&style_main, 0);
        lv_style_set_border_width(&style_main, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLL_ONE, true);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_add_event_cb(lv_obj_0, view_selected_cb, LV_EVENT_CLICKED, screen);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, preview);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "item_#");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

