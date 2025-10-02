/**
 * @file screen2_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen2_gen.h"
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

lv_obj_t * screen2_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_arc;
    static lv_style_t style_indicator;
    static lv_style_t style_knob;
    static lv_style_t style_cont;
    static lv_style_t style_label;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0x000000));

        lv_style_init(&style_arc);
        lv_style_set_width(&style_arc, 466);
        lv_style_set_height(&style_arc, 466);
        lv_style_set_transform_pivot_x(&style_arc, 233);
        lv_style_set_transform_pivot_y(&style_arc, 233);
        lv_style_set_transform_rotation(&style_arc, -900);
        lv_style_set_arc_width(&style_arc, 55);
        lv_style_set_arc_color(&style_arc, lv_color_hex(0x3E3C8D));
        lv_style_set_radius(&style_arc, 5);

        lv_style_init(&style_indicator);
        lv_style_set_arc_width(&style_indicator, 55);
        lv_style_set_arc_color(&style_indicator, lv_color_hex(0x0DA5E9));
        lv_style_set_arc_opa(&style_indicator, 200);
        lv_style_set_arc_rounded(&style_indicator, false);
        lv_style_set_border_width(&style_indicator, 1);
        lv_style_set_border_color(&style_indicator, lv_color_hex3(0x000));

        lv_style_init(&style_knob);
        lv_style_set_bg_opa(&style_knob, 0);
        lv_style_set_radius(&style_knob, 0);

        lv_style_init(&style_cont);
        lv_style_set_layout(&style_cont, LV_LAYOUT_FLEX);
        lv_style_set_flex_cross_place(&style_cont, LV_FLEX_ALIGN_CENTER);
        lv_style_set_bg_opa(&style_cont, 0);
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_height(&style_cont, LV_SIZE_CONTENT);
        lv_style_set_width(&style_cont, LV_SIZE_CONTENT);
        lv_style_set_pad_all(&style_cont, 0);
        lv_style_set_text_color(&style_cont, lv_color_hex3(0xfff));
        lv_style_set_text_font(&style_cont, montserrat_semibold_19);
        lv_style_set_transform_rotation(&style_cont, -900);

        lv_style_init(&style_label);
        lv_style_set_bg_color(&style_label, lv_color_hex(0x6E7681));
        lv_style_set_bg_opa(&style_label, (255 * 40 / 100));
        lv_style_set_pad_all(&style_label, 10);
        lv_style_set_radius(&style_label, 20);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * stats_arc = lv_arc_create(lv_obj_0);
    lv_obj_set_name(stats_arc, "stats_arc");
    lv_arc_set_bg_start_angle(stats_arc, 0);
    lv_arc_set_bg_end_angle(stats_arc, 360);
    lv_arc_set_mode(stats_arc, LV_ARC_MODE_REVERSE);
    lv_arc_set_value(stats_arc, 40);
    lv_arc_bind_value(stats_arc, &subject_issues);
    lv_obj_set_flag(stats_arc, LV_OBJ_FLAG_CLICKABLE, false);
    lv_obj_add_style(stats_arc, &style_arc, 0);
    lv_obj_add_style(stats_arc, &style_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(stats_arc, &style_knob, LV_PART_KNOB);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_CENTER);
    lv_obj_set_x(lv_obj_1, -52);
    lv_obj_set_y(lv_obj_1, 95);
    lv_obj_set_width(lv_obj_1, 151);
    lv_obj_set_height(lv_obj_1, 40);
    lv_obj_add_style(lv_obj_1, &style_cont, 0);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_1);
    lv_image_set_src(lv_image_0, issue2_icon);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_0, "Issues");
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_1, "100");
    lv_label_bind_text(lv_label_1, &subject_issues, NULL);
    lv_obj_add_style(lv_label_1, &style_label, 0);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_2, "20:34");
    lv_label_bind_text(lv_label_2, &subject_time, NULL);
    lv_obj_set_align(lv_label_2, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_label_2, 100);
    lv_obj_set_style_text_color(lv_label_2, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(lv_label_2, montserrat_semibold_60, 0);
    
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_3, "Github Repo");
    lv_label_bind_text(lv_label_3, &subject_name, NULL);
    lv_obj_set_align(lv_label_3, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_label_3, 300);
    lv_obj_set_style_text_color(lv_label_3, lv_color_hex(0x333FFF), 0);
    lv_obj_set_style_text_font(lv_label_3, montserrat_semibold_23, 0);
    
    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_2, LV_ALIGN_CENTER);
    lv_obj_set_x(lv_obj_2, 191);
    lv_obj_set_y(lv_obj_2, 128);
    lv_obj_add_style(lv_obj_2, &style_cont, 0);
    lv_obj_t * lv_image_1 = lv_image_create(lv_obj_2);
    lv_image_set_src(lv_image_1, pr2_icon);
    
    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_4, "Pull requests");
    
    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_5, "100");
    lv_label_bind_text(lv_label_5, &subject_prs, NULL);
    lv_obj_add_style(lv_label_5, &style_label, 0);
    
    lv_obj_t * lv_image_2 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_2, github_logo);
    lv_obj_set_align(lv_image_2, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_3, LV_ALIGN_TOP_MID);
    lv_obj_set_x(lv_obj_3, -1);
    lv_obj_set_y(lv_obj_3, 340);
    lv_obj_set_style_transform_rotation(lv_obj_3, 0, 0);
    lv_obj_add_style(lv_obj_3, &style_cont, 0);
    lv_obj_t * lv_image_3 = lv_image_create(lv_obj_3);
    lv_image_set_src(lv_image_3, star2_icon);
    
    lv_obj_t * lv_label_6 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_6, "3.6k");
    lv_label_bind_text(lv_label_6, &subject_stars, NULL);
    
    lv_obj_t * lv_label_7 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_7, "stars");

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "screen2");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

