/**
 * @file stats_ui_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "stats_ui_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * montserrat_semibold_19;
extern lv_font_t montserrat_semibold_19_data;
lv_font_t * montserrat_semibold_23;
extern lv_font_t montserrat_semibold_23_data;
lv_font_t * montserrat_semibold_60;
extern lv_font_t montserrat_semibold_60_data;
lv_font_t * sp_elite_64;
extern lv_font_t sp_elite_64_data;
lv_font_t * sf_pro_20;
extern lv_font_t sf_pro_20_data;
lv_font_t * sf_pro_24;
extern lv_font_t sf_pro_24_data;
lv_font_t * sf_pro_40;
extern lv_font_t sf_pro_40_data;
lv_font_t * inter_medium_24;
extern lv_font_t inter_medium_24_data;
lv_font_t * inter_medium_33;
extern lv_font_t inter_medium_33_data;
lv_font_t * inter_medium_36;
extern lv_font_t inter_medium_36_data;
lv_font_t * inter_medium_40;
extern lv_font_t inter_medium_40_data;
lv_font_t * inter_medium_48;
extern lv_font_t inter_medium_48_data;
lv_font_t * bodoni_48;
extern lv_font_t bodoni_48_data;
lv_font_t * dm_serif_15;
extern lv_font_t dm_serif_15_data;

/*----------------
 * Images
 *----------------*/

const void * star_icon;
extern const void * star_icon_data;
const void * wifi_icon;
extern const void * wifi_icon_data;
const void * github_logo;
extern const void * github_logo_data;
const void * overlay;
extern const void * overlay_data;
const void * star2_icon;
extern const void * star2_icon_data;
const void * issue2_icon;
extern const void * issue2_icon_data;
const void * pr2_icon;
extern const void * pr2_icon_data;
const void * star3_icon;
extern const void * star3_icon_data;
const void * star4_icon;
extern const void * star4_icon_data;
const void * pr4_icon;
extern const void * pr4_icon_data;
const void * merge4_icon;
extern const void * merge4_icon_data;
const void * main_preview;
extern const void * main_preview_data;
const void * screen2_preview;
extern const void * screen2_preview_data;
const void * screen3_preview;
extern const void * screen3_preview_data;
const void * screen4_preview;
extern const void * screen4_preview_data;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_time;
lv_subject_t subject_date;
lv_subject_t subject_name;
lv_subject_t subject_stars;
lv_subject_t subject_prs;
lv_subject_t subject_issues;
lv_subject_t subject_wifi;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void stats_ui_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Fonts
     *----------------*/

    /* get font 'montserrat_semibold_19' from a C array */
    montserrat_semibold_19 = &montserrat_semibold_19_data;
    /* get font 'montserrat_semibold_23' from a C array */
    montserrat_semibold_23 = &montserrat_semibold_23_data;
    /* get font 'montserrat_semibold_60' from a C array */
    montserrat_semibold_60 = &montserrat_semibold_60_data;
    /* get font 'sp_elite_64' from a C array */
    sp_elite_64 = &sp_elite_64_data;
    /* get font 'sf_pro_20' from a C array */
    sf_pro_20 = &sf_pro_20_data;
    /* get font 'sf_pro_24' from a C array */
    sf_pro_24 = &sf_pro_24_data;
    /* get font 'sf_pro_40' from a C array */
    sf_pro_40 = &sf_pro_40_data;
    /* get font 'inter_medium_24' from a C array */
    inter_medium_24 = &inter_medium_24_data;
    /* get font 'inter_medium_33' from a C array */
    inter_medium_33 = &inter_medium_33_data;
    /* get font 'inter_medium_36' from a C array */
    inter_medium_36 = &inter_medium_36_data;
    /* get font 'inter_medium_40' from a C array */
    inter_medium_40 = &inter_medium_40_data;
    /* get font 'inter_medium_48' from a C array */
    inter_medium_48 = &inter_medium_48_data;
    /* get font 'bodoni_48' from a C array */
    bodoni_48 = &bodoni_48_data;
    /* get font 'dm_serif_15' from a C array */
    dm_serif_15 = &dm_serif_15_data;


    /*----------------
     * Images
     *----------------*/
    star_icon = &star_icon_data;
    wifi_icon = &wifi_icon_data;
    github_logo = &github_logo_data;
    overlay = &overlay_data;
    star2_icon = &star2_icon_data;
    issue2_icon = &issue2_icon_data;
    pr2_icon = &pr2_icon_data;
    star3_icon = &star3_icon_data;
    star4_icon = &star4_icon_data;
    pr4_icon = &pr4_icon_data;
    merge4_icon = &merge4_icon_data;
    main_preview = &main_preview_data;
    screen2_preview = &screen2_preview_data;
    screen3_preview = &screen3_preview_data;
    screen4_preview = &screen4_preview_data;

    /*----------------
     * Subjects
     *----------------*/
    static char subject_time_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_time_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_time,
                           subject_time_buf,
                           subject_time_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "10:20"
                          );
    static char subject_date_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_date_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_date,
                           subject_date_buf,
                           subject_date_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Sat 27"
                          );
    static char subject_name_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_name_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_name,
                           subject_name_buf,
                           subject_name_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Project"
                          );
    lv_subject_init_int(&subject_stars, 345);
    lv_subject_init_int(&subject_prs, 35);
    lv_subject_init_int(&subject_issues, 27);
    lv_subject_init_int(&subject_wifi, 1);

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */
    lv_xml_register_font(NULL, "montserrat_semibold_19", montserrat_semibold_19);
    lv_xml_register_font(NULL, "montserrat_semibold_23", montserrat_semibold_23);
    lv_xml_register_font(NULL, "montserrat_semibold_60", montserrat_semibold_60);
    lv_xml_register_font(NULL, "sp_elite_64", sp_elite_64);
    lv_xml_register_font(NULL, "sf_pro_20", sf_pro_20);
    lv_xml_register_font(NULL, "sf_pro_24", sf_pro_24);
    lv_xml_register_font(NULL, "sf_pro_40", sf_pro_40);
    lv_xml_register_font(NULL, "inter_medium_24", inter_medium_24);
    lv_xml_register_font(NULL, "inter_medium_33", inter_medium_33);
    lv_xml_register_font(NULL, "inter_medium_36", inter_medium_36);
    lv_xml_register_font(NULL, "inter_medium_40", inter_medium_40);
    lv_xml_register_font(NULL, "inter_medium_48", inter_medium_48);
    lv_xml_register_font(NULL, "bodoni_48", bodoni_48);
    lv_xml_register_font(NULL, "dm_serif_15", dm_serif_15);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_time", &subject_time);
    lv_xml_register_subject(NULL, "subject_date", &subject_date);
    lv_xml_register_subject(NULL, "subject_name", &subject_name);
    lv_xml_register_subject(NULL, "subject_stars", &subject_stars);
    lv_xml_register_subject(NULL, "subject_prs", &subject_prs);
    lv_xml_register_subject(NULL, "subject_issues", &subject_issues);
    lv_xml_register_subject(NULL, "subject_wifi", &subject_wifi);

    /* Register callbacks */
    lv_xml_register_event_cb(NULL, "view_selected_cb", view_selected_cb);
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "star_icon", star_icon);
    lv_xml_register_image(NULL, "wifi_icon", wifi_icon);
    lv_xml_register_image(NULL, "github_logo", github_logo);
    lv_xml_register_image(NULL, "overlay", overlay);
    lv_xml_register_image(NULL, "star2_icon", star2_icon);
    lv_xml_register_image(NULL, "issue2_icon", issue2_icon);
    lv_xml_register_image(NULL, "pr2_icon", pr2_icon);
    lv_xml_register_image(NULL, "star3_icon", star3_icon);
    lv_xml_register_image(NULL, "star4_icon", star4_icon);
    lv_xml_register_image(NULL, "pr4_icon", pr4_icon);
    lv_xml_register_image(NULL, "merge4_icon", merge4_icon);
    lv_xml_register_image(NULL, "main_preview", main_preview);
    lv_xml_register_image(NULL, "screen2_preview", screen2_preview);
    lv_xml_register_image(NULL, "screen3_preview", screen3_preview);
    lv_xml_register_image(NULL, "screen4_preview", screen4_preview);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */
#if defined(LV_EDITOR_PREVIEW)
void __attribute__((weak)) view_selected_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("view_selected_cb was called\n");
}
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/