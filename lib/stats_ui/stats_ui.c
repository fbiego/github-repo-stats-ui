/**
 * @file stats_ui.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "stats_ui.h"

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

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void stats_ui_init(const char * asset_path)
{
    stats_ui_init_gen(asset_path);
}

void view_selected_cb(lv_event_t * e)
{

    lv_obj_t * screen = (lv_obj_t *)lv_event_get_user_data(e);
    if (screen)
    {
        lv_screen_load(screen);
    }

}

/**********************
 *   STATIC FUNCTIONS
 **********************/