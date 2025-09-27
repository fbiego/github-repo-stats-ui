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

extern lv_font_t * sp_elite_64;

extern lv_font_t * sf_pro_20;

extern lv_font_t * sf_pro_24;

extern lv_font_t * sf_pro_40;

/*----------------
 * Images
 *----------------*/

extern const void * star_icon;
extern const void * wifi_icon;
extern const void * github_logo;
extern const void * overlay;

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
#include "screens/main_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*STATS_UI_GEN_H*/