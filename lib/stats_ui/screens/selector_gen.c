/**
 * @file selector_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "selector_gen.h"
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

lv_obj_t * selector_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_cont;
    static lv_style_t style_bars;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_layout(&style_main, LV_LAYOUT_FLEX);
        lv_style_set_flex_cross_place(&style_main, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_main, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_all(&style_main, 50);
        lv_style_set_pad_column(&style_main, 50);

        lv_style_init(&style_cont);
        lv_style_set_width(&style_cont, 200);
        lv_style_set_height(&style_cont, 200);
        lv_style_set_radius(&style_cont, 100);

        lv_style_init(&style_bars);
        lv_style_set_bg_opa(&style_bars, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_scroll_snap_x(lv_obj_0, LV_SCROLL_SNAP_CENTER);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_add_style(lv_obj_0, &style_bars, LV_PART_SCROLLBAR);
    lv_obj_add_style(lv_obj_0, &style_bars, LV_PART_SCROLLBAR | LV_STATE_SCROLLED);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "selector");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

