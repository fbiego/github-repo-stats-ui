/**
 * @file main_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "main_gen.h"
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

lv_obj_t * main_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_round;
    static lv_style_t style_time;
    static lv_style_t style_stats;
    static lv_style_t style_cont;
    static lv_style_t style_arc;
    static lv_style_t style_indicator;
    static lv_style_t style_knob;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0x0F0F0F));

        lv_style_init(&style_round);
        lv_style_set_width(&style_round, 360);
        lv_style_set_height(&style_round, 360);
        lv_style_set_radius(&style_round, 180);
        lv_style_set_bg_color(&style_round, lv_color_hex(0x161616));
        lv_style_set_border_width(&style_round, 0);

        lv_style_init(&style_time);
        lv_style_set_width(&style_time, 198);
        lv_style_set_height(&style_time, 76);
        lv_style_set_radius(&style_time, 38);
        lv_style_set_bg_color(&style_time, lv_color_hex(0x171717));
        lv_style_set_border_width(&style_time, 0);
        lv_style_set_text_font(&style_time, sp_elite_64);
        lv_style_set_text_color(&style_time, lv_color_hex(0x9AE98A));
        lv_style_set_pad_all(&style_time, 0);

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
        lv_style_set_text_font(&style_stats, montserrat_semibold_19);
        lv_style_set_text_color(&style_stats, lv_color_hex(0xF5F5F5));
        lv_style_set_border_width(&style_stats, 0);

        lv_style_init(&style_cont);
        lv_style_set_layout(&style_cont, LV_LAYOUT_FLEX);
        lv_style_set_bg_opa(&style_cont, 0);
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_height(&style_cont, LV_SIZE_CONTENT);
        lv_style_set_width(&style_cont, LV_SIZE_CONTENT);
        lv_style_set_pad_all(&style_cont, 0);

        lv_style_init(&style_arc);
        lv_style_set_width(&style_arc, 466);
        lv_style_set_height(&style_arc, 466);
        lv_style_set_transform_pivot_x(&style_arc, 233);
        lv_style_set_transform_pivot_y(&style_arc, 233);
        lv_style_set_transform_rotation(&style_arc, -900);
        lv_style_set_arc_width(&style_arc, 55);
        lv_style_set_arc_color(&style_arc, lv_color_hex(0x045A7C));

        lv_style_init(&style_indicator);
        lv_style_set_arc_width(&style_indicator, 55);
        lv_style_set_arc_color(&style_indicator, lv_color_hex(0x24EAA2));

        lv_style_init(&style_knob);
        lv_style_set_bg_opa(&style_knob, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_x(lv_obj_1, -228);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_LEFT_MID);
    lv_obj_add_style(lv_obj_1, &style_round, 0);
    
    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_0);
    lv_obj_set_x(lv_obj_2, 228);
    lv_obj_set_align(lv_obj_2, LV_ALIGN_RIGHT_MID);
    lv_obj_add_style(lv_obj_2, &style_round, 0);
    
    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_0);
    lv_obj_set_y(lv_obj_3, 110);
    lv_obj_set_align(lv_obj_3, LV_ALIGN_TOP_MID);
    lv_obj_set_flag(lv_obj_3, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_add_style(lv_obj_3, &style_time, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_3);
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    lv_label_set_text(lv_label_0, "10:10");
    lv_label_bind_text(lv_label_0, &subject_time, NULL);
    
    lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_4, LV_ALIGN_TOP_MID);
    lv_obj_set_width(lv_obj_4, 150);
    lv_obj_set_y(lv_obj_4, 80);
    lv_obj_set_style_flex_main_place(lv_obj_4, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_add_style(lv_obj_4, &style_cont, 0);
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_4);
    lv_label_set_text(lv_label_1, "Fri 26");
    lv_label_bind_text(lv_label_1, &subject_date, NULL);
    lv_obj_set_style_text_font(lv_label_1, sf_pro_20, 0);
    lv_obj_set_style_text_color(lv_label_1, lv_color_hex(0x9AE98A), 0);
    
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_4);
    lv_image_set_src(lv_image_0, wifi_icon);
    lv_obj_bind_flag_if_eq(lv_image_0, &subject_wifi, LV_OBJ_FLAG_HIDDEN, 0);
    
    lv_obj_t * lv_image_1 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_1, github_logo);
    lv_obj_set_align(lv_image_1, LV_ALIGN_CENTER);
    lv_obj_set_y(lv_image_1, 10);
    
    lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_0);
    lv_obj_set_x(lv_obj_5, 60);
    lv_obj_set_align(lv_obj_5, LV_ALIGN_LEFT_MID);
    lv_obj_add_style(lv_obj_5, &style_stats, 0);
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_5);
    lv_label_set_text(lv_label_2, "100");
    lv_label_bind_text(lv_label_2, &subject_issues, NULL);
    lv_obj_set_style_text_color(lv_label_2, lv_color_hex(0x24EAA2), 0);
    lv_obj_set_style_text_font(lv_label_2, sf_pro_24, 0);
    
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_5);
    lv_label_set_text(lv_label_3, "Issues");
    
    lv_obj_t * lv_obj_6 = lv_obj_create(lv_obj_0);
    lv_obj_set_x(lv_obj_6, -70);
    lv_obj_set_align(lv_obj_6, LV_ALIGN_RIGHT_MID);
    lv_obj_add_style(lv_obj_6, &style_stats, 0);
    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_6);
    lv_label_set_text(lv_label_4, "100");
    lv_label_bind_text(lv_label_4, &subject_prs, NULL);
    lv_obj_set_style_text_color(lv_label_4, lv_color_hex(0x24EAA2), 0);
    lv_obj_set_style_text_font(lv_label_4, sf_pro_24, 0);
    
    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_6);
    lv_label_set_text(lv_label_5, "PRs");
    
    lv_obj_t * lv_label_6 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_6, "Smart Watch App");
    lv_label_bind_text(lv_label_6, &subject_name, NULL);
    lv_obj_set_y(lv_label_6, 300);
    lv_obj_set_align(lv_label_6, LV_ALIGN_TOP_MID);
    lv_obj_set_style_text_font(lv_label_6, montserrat_semibold_23, 0);
    lv_obj_set_style_text_color(lv_label_6, lv_color_hex(0xF5F5F5), 0);
    
    lv_obj_t * lv_obj_7 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_7, LV_ALIGN_TOP_MID);
    lv_obj_set_width(lv_obj_7, LV_SIZE_CONTENT);
    lv_obj_set_y(lv_obj_7, 330);
    lv_obj_set_style_flex_main_place(lv_obj_7, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(lv_obj_7, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_column(lv_obj_7, 0, 0);
    lv_obj_add_style(lv_obj_7, &style_cont, 0);
    lv_obj_t * lv_image_2 = lv_image_create(lv_obj_7);
    lv_image_set_src(lv_image_2, star_icon);
    
    lv_obj_t * lv_label_7 = lv_label_create(lv_obj_7);
    lv_label_set_text(lv_label_7, "100");
    lv_label_bind_text(lv_label_7, &subject_stars, NULL);
    lv_obj_set_style_text_font(lv_label_7, sf_pro_40, 0);
    lv_obj_set_style_text_color(lv_label_7, lv_color_hex(0xF5F5F5), 0);
    lv_obj_set_style_pad_top(lv_label_7, 5, 0);
    
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
    
    lv_obj_t * lv_image_3 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_3, overlay);
    lv_obj_set_style_opa(lv_image_3, 150, 0);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "main");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

