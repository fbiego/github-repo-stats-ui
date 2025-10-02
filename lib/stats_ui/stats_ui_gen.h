/**
 * @file stats_ui_gen.h
 */

#ifndef STATS_UI_GEN_H
#define STATS_UI_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * montserrat_semibold_19;

extern lv_font_t * montserrat_semibold_23;

extern lv_font_t * montserrat_semibold_60;

extern lv_font_t * sp_elite_64;

extern lv_font_t * sf_pro_20;

extern lv_font_t * sf_pro_24;

extern lv_font_t * sf_pro_40;

extern lv_font_t * inter_medium_24;

extern lv_font_t * inter_medium_33;

extern lv_font_t * inter_medium_36;

extern lv_font_t * inter_medium_40;

extern lv_font_t * inter_medium_48;

extern lv_font_t * bodoni_48;

extern lv_font_t * dm_serif_15;

/*----------------
 * Images
 *----------------*/

extern const void * star_icon;
extern const void * wifi_icon;
extern const void * github_logo;
extern const void * overlay;
extern const void * star2_icon;
extern const void * issue2_icon;
extern const void * pr2_icon;
extern const void * star3_icon;
extern const void * star4_icon;
extern const void * pr4_icon;
extern const void * merge4_icon;
extern const void * main_preview;
extern const void * screen2_preview;
extern const void * screen3_preview;
extern const void * screen4_preview;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_time;
extern lv_subject_t subject_date;
extern lv_subject_t subject_name;
extern lv_subject_t subject_stars;
extern lv_subject_t subject_prs;
extern lv_subject_t subject_issues;
extern lv_subject_t subject_wifi;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

void view_selected_cb(lv_event_t * e);

/**
 * Initialize the component library
 */

void stats_ui_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widget and components of this library*/
#include "components/item_gen.h"
#include "screens/main_gen.h"
#include "screens/screen2_gen.h"
#include "screens/screen3_gen.h"
#include "screens/screen4_gen.h"
#include "screens/selector_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*STATS_UI_GEN_H*/