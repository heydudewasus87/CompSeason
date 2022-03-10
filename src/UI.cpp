#include "UI.h"

extern int autoSelection;

namespace vpi {
  namespace ui {
    using namespace vpi;

    const char *btnmMap1[] = {"1*", "\n", "2", "\n", "3", ""};
    const char *btnmMap2[] = {"1", "\n", "2*", "\n", "3", ""};
    const char *btnmMap3[] = {"1", "\n", "2", "\n", "3*", ""};
    lv_obj_t *datBtnm;

    void btnmEventHandler(lv_obj_t * obj, lv_event_t e){
      if (e == LV_EVENT_VALUE_CHANGED) {
        //const char * txt = lv_btnmatrix_get_active_btn_text(obj);
        autoSelection = lv_btnmatrix_get_active_btn(obj);
        if (autoSelection == 0) {
          lv_btnmatrix_set_map(datBtnm, btnmMap1);
        }
        else if (autoSelection == 1) {
          lv_btnmatrix_set_map(datBtnm, btnmMap2);
        }
        else if (autoSelection == 2) {
          lv_btnmatrix_set_map(datBtnm, btnmMap3);
        }    
      }
    }

    void uiInit(){
      // Set the full screen background to Black
      static lv_style_t style_screen;
      // LV_STYLE_BG_COLOR
      lv_style_set_bg_color(&style_screen, LV_STATE_DEFAULT, LV_COLOR_BLACK);
      lv_obj_add_style(lv_scr_act(),LV_OBJ_PART_MAIN, &style_screen);

      static lv_style_t style1;
      static lv_style_t style2;
      static lv_style_t style3;
      lv_style_set_bg_color(&style1, LV_STATE_DEFAULT, LV_COLOR_BLACK);
      lv_style_set_bg_color(&style1, LV_STATE_PRESSED, LV_COLOR_GRAY);
      lv_style_set_bg_color(&style2, LV_STATE_CHECKED | LV_STATE_FOCUSED | LV_STATE_DEFAULT, LV_COLOR_PURPLE);
      lv_style_set_text_color(&style3, LV_STATE_DEFAULT, LV_COLOR_WHITE);

      // Create the DAT button matrix
      datBtnm = lv_btnmatrix_create(lv_scr_act(), NULL);
      lv_btnmatrix_set_map(datBtnm, btnmMap1);
      lv_obj_set_size(datBtnm, 100, 200);
      lv_obj_set_pos(datBtnm, 0, 0);
      lv_obj_align(datBtnm, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 10);
      lv_obj_set_event_cb(datBtnm, btnmEventHandler);
      lv_obj_add_style(datBtnm,LV_BTNMATRIX_PART_BG, &style1);
      lv_obj_add_style(datBtnm,LV_BTNMATRIX_PART_BTN, &style2);
    }
  } // namespace ui
} // namespace vpi