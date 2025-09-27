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
lv_font_t * sp_elite_64;
extern lv_font_t sp_elite_64_data;
lv_font_t * sf_pro_20;
extern lv_font_t sf_pro_20_data;
lv_font_t * sf_pro_24;
extern lv_font_t sf_pro_24_data;
lv_font_t * sf_pro_40;
extern lv_font_t sf_pro_40_data;

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
    /* get font 'sp_elite_64' from a C array */
    sp_elite_64 = &sp_elite_64_data;
    /* get font 'sf_pro_20' from a C array */
    sf_pro_20 = &sf_pro_20_data;
    /* get font 'sf_pro_24' from a C array */
    sf_pro_24 = &sf_pro_24_data;
    /* get font 'sf_pro_40' from a C array */
    sf_pro_40 = &sf_pro_40_data;


    /*----------------
     * Images
     *----------------*/
    star_icon = &star_icon_data;
    wifi_icon = &wifi_icon_data;
    github_logo = &github_logo_data;
    overlay = &overlay_data;

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
    lv_xml_register_font(NULL, "sp_elite_64", sp_elite_64);
    lv_xml_register_font(NULL, "sf_pro_20", sf_pro_20);
    lv_xml_register_font(NULL, "sf_pro_24", sf_pro_24);
    lv_xml_register_font(NULL, "sf_pro_40", sf_pro_40);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_time", &subject_time);
    lv_xml_register_subject(NULL, "subject_date", &subject_date);
    lv_xml_register_subject(NULL, "subject_name", &subject_name);
    lv_xml_register_subject(NULL, "subject_stars", &subject_stars);
    lv_xml_register_subject(NULL, "subject_prs", &subject_prs);
    lv_xml_register_subject(NULL, "subject_issues", &subject_issues);
    lv_xml_register_subject(NULL, "subject_wifi", &subject_wifi);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "star_icon", star_icon);
    lv_xml_register_image(NULL, "wifi_icon", wifi_icon);
    lv_xml_register_image(NULL, "github_logo", github_logo);
    lv_xml_register_image(NULL, "overlay", overlay);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     *manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/