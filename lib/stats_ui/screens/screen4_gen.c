/**
 * @file screen4_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen4_gen.h"
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

lv_obj_t * screen4_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_round;
    static lv_style_t style_cont;
    static lv_style_t style_stats;
    static lv_style_t style_arc;
    static lv_style_t style_indicator;
    static lv_style_t style_label;
    static lv_style_t style_knob;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0x1e1e1e));

        lv_style_init(&style_round);
        lv_style_set_width(&style_round, 231);
        lv_style_set_height(&style_round, 231);
        lv_style_set_radius(&style_round, 180);
        lv_style_set_bg_color(&style_round, lv_color_hex(0x161616));
        lv_style_set_border_width(&style_round, 30);

        lv_style_init(&style_cont);
        lv_style_set_layout(&style_cont, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_cont, LV_FLEX_FLOW_COLUMN);
        lv_style_set_bg_opa(&style_cont, 255);
        lv_style_set_bg_color(&style_cont, lv_color_hex(0xD9D9D9));
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_height(&style_cont, LV_SIZE_CONTENT);
        lv_style_set_width(&style_cont, LV_SIZE_CONTENT);
        lv_style_set_pad_all(&style_cont, 0);
        lv_style_set_pad_row(&style_cont, -17);

        lv_style_init(&style_stats);
        lv_style_set_width(&style_stats, LV_SIZE_CONTENT);
        lv_style_set_height(&style_stats, LV_SIZE_CONTENT);
        lv_style_set_pad_all(&style_stats, 0);
        lv_style_set_pad_row(&style_stats, 0);
        lv_style_set_layout(&style_stats, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_stats, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_main_place(&style_stats, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_stats, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_stats, LV_FLEX_ALIGN_CENTER);
        lv_style_set_bg_opa(&style_stats, 0);
        lv_style_set_text_font(&style_stats, inter_medium_24);
        lv_style_set_text_color(&style_stats, lv_color_hex(0xF5F5F5));
        lv_style_set_border_width(&style_stats, 0);

        lv_style_init(&style_arc);
        lv_style_set_width(&style_arc, 466);
        lv_style_set_height(&style_arc, 466);
        lv_style_set_transform_pivot_x(&style_arc, 233);
        lv_style_set_transform_pivot_y(&style_arc, 233);
        lv_style_set_transform_rotation(&style_arc, -900);
        lv_style_set_arc_width(&style_arc, 35);
        lv_style_set_arc_color(&style_arc, lv_color_hex(0xF7504F));
        lv_style_set_radius(&style_arc, 5);

        lv_style_init(&style_indicator);
        lv_style_set_arc_width(&style_indicator, 35);
        lv_style_set_arc_color(&style_indicator, lv_color_hex(0xD0CECD));
        lv_style_set_arc_opa(&style_indicator, 200);
        lv_style_set_arc_rounded(&style_indicator, false);
        lv_style_set_border_width(&style_indicator, 1);
        lv_style_set_border_color(&style_indicator, lv_color_hex3(0x000));

        lv_style_init(&style_label);
        lv_style_set_text_color(&style_label, lv_color_hex(0x000000));
        lv_style_set_text_font(&style_label, sf_pro_24);
        lv_style_set_bg_color(&style_label, lv_color_hex(0xffffff));
        lv_style_set_bg_opa(&style_label, 255);
        lv_style_set_pad_all(&style_label, 5);
        lv_style_set_radius(&style_label, 5);
        lv_style_set_pad_left(&style_label, 10);
        lv_style_set_pad_right(&style_label, 10);
        lv_style_set_pad_top(&style_label, 7);

        lv_style_init(&style_knob);
        lv_style_set_bg_opa(&style_knob, 0);
        lv_style_set_radius(&style_knob, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_x(lv_obj_1, -100);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_LEFT_MID);
    lv_obj_add_style(lv_obj_1, &style_round, 0);
    
    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_0);
    lv_obj_set_x(lv_obj_2, 100);
    lv_obj_set_align(lv_obj_2, LV_ALIGN_RIGHT_MID);
    lv_obj_add_style(lv_obj_2, &style_round, 0);
    
    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_0);
    lv_obj_set_width(lv_obj_3, 147);
    lv_obj_set_height(lv_obj_3, 75);
    lv_obj_set_align(lv_obj_3, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_obj_3, 80);
    lv_obj_set_flag(lv_obj_3, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_add_style(lv_obj_3, &style_cont, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_3);
    lv_label_bind_text(lv_label_0, &subject_date, NULL);
    lv_obj_set_style_text_font(lv_label_0, dm_serif_15, 0);
    lv_obj_set_style_pad_left(lv_label_0, 5, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_1, "100");
    lv_label_bind_text(lv_label_1, &subject_time, NULL);
    lv_obj_set_style_text_font(lv_label_1, bodoni_48, 0);
    lv_obj_set_style_text_color(lv_label_1, lv_color_hex(0xF7504F), 0);
    
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, github_logo);
    lv_obj_set_align(lv_image_0, LV_ALIGN_CENTER);
    lv_obj_set_y(lv_image_0, -10);
    
    lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_0);
    lv_obj_set_x(lv_obj_4, 50);
    lv_obj_set_align(lv_obj_4, LV_ALIGN_LEFT_MID);
    lv_obj_add_style(lv_obj_4, &style_stats, 0);
    lv_obj_t * lv_image_1 = lv_image_create(lv_obj_4);
    lv_image_set_src(lv_image_1, merge4_icon);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_4);
    lv_label_set_text(lv_label_2, "100");
    lv_label_bind_text(lv_label_2, &subject_issues, NULL);
    lv_obj_set_style_text_font(lv_label_2, dm_serif_15, 0);
    
    lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_0);
    lv_obj_set_x(lv_obj_5, -50);
    lv_obj_set_align(lv_obj_5, LV_ALIGN_RIGHT_MID);
    lv_obj_add_style(lv_obj_5, &style_stats, 0);
    lv_obj_t * lv_image_2 = lv_image_create(lv_obj_5);
    lv_image_set_src(lv_image_2, pr4_icon);
    
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_5);
    lv_label_set_text(lv_label_3, "100");
    lv_label_bind_text(lv_label_3, &subject_prs, NULL);
    lv_obj_set_style_text_font(lv_label_3, dm_serif_15, 0);
    
    lv_obj_t * lv_obj_6 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_6, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_y(lv_obj_6, -50);
    lv_obj_set_style_pad_row(lv_obj_6, 10, 0);
    lv_obj_add_style(lv_obj_6, &style_stats, 0);
    lv_obj_t * lv_image_3 = lv_image_create(lv_obj_6);
    lv_image_set_src(lv_image_3, star4_icon);
    
    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_6);
    lv_label_set_text(lv_label_4, "100");
    lv_label_bind_text(lv_label_4, &subject_stars, NULL);
    lv_obj_set_style_text_font(lv_label_4, sf_pro_24, 0);
    
    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_5, "Smart Watch App");
    lv_label_bind_text(lv_label_5, &subject_name, NULL);
    lv_obj_set_y(lv_label_5, 300);
    lv_obj_set_align(lv_label_5, LV_ALIGN_TOP_MID);
    lv_obj_add_style(lv_label_5, &style_label, 0);
    
    lv_obj_t * stats_arc = lv_arc_create(lv_obj_0);
    lv_obj_set_name(stats_arc, "stats_arc");
    lv_arc_set_bg_start_angle(stats_arc, 0);
    lv_arc_set_bg_end_angle(stats_arc, 360);
    lv_arc_set_value(stats_arc, 40);
    lv_arc_set_mode(stats_arc, LV_ARC_MODE_REVERSE);
    lv_arc_bind_value(stats_arc, &subject_issues);
    lv_obj_set_flag(stats_arc, LV_OBJ_FLAG_CLICKABLE, false);
    lv_obj_add_style(stats_arc, &style_arc, 0);
    lv_obj_add_style(stats_arc, &style_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(stats_arc, &style_knob, LV_PART_KNOB);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "screen4");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

