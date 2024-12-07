// Copyright 2024 Hashikure-engineering
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,   MS_BTN1 ,   MS_BTN2    , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_ESC   , MT(MOD_LGUI, KC_LNG1), MT(MOD_LSFT, KC_TAB), LT(1, KC_SPC),LT(2, KC_ENT), LT(3, KC_BSPC) , LT(4, KC_LNG2)      , KC_RALT
  ),

  [1] = LAYOUT(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,   MS_BTN1 ,   MS_BTN2    , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_ESC   , MT(MOD_LGUI, KC_LNG1), MT(MOD_LSFT, KC_TAB), LT(1, KC_SPC),LT(2, KC_ENT), LT(3, KC_BSPC) ,LT(4, KC_LNG2)       , KC_RALT
  ),

  [2] = LAYOUT(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,   MS_BTN1 ,   MS_BTN2    , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_ESC   , MT(MOD_LGUI, KC_LNG1), MT(MOD_LSFT, KC_TAB), LT(1, KC_SPC),LT(2, KC_ENT), LT(3, KC_BSPC) ,LT(4, KC_LNG2)       , KC_RALT
  ),

  [3] = LAYOUT(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,   MS_BTN1 ,   MS_BTN2    , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_ESC   , MT(MOD_LGUI, KC_LNG1), MT(MOD_LSFT, KC_TAB), LT(1, KC_SPC),LT(2, KC_ENT), LT(3, KC_BSPC) ,LT(4, KC_LNG2)       , KC_RALT
  ),

  [4] = LAYOUT(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            CPI_DEC     , CPI_INC     , KBC_RST     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            SCR_INC     , SCR_DEC     , KC_L     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,   MS_BTN1 ,   MS_BTN2    , SCR_H_REV     , SCR_V_REV     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_ESC   , MT(MOD_LGUI, KC_LNG1), MT(MOD_LSFT, KC_TAB), LT(1, KC_SPC),LT(2, KC_ENT), LT(3, KC_BSPC) ,LT(4, KC_LNG2)       , KC_RALT
  ),

  [5] = LAYOUT(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,   MS_BTN1 ,   MS_BTN2    , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_ESC   , MT(MOD_LGUI, KC_LNG1), MT(MOD_LSFT, KC_TAB), LT(1, KC_SPC),LT(2, KC_ENT), LT(3, KC_BSPC) ,LT(4, KC_LNG2)       , KC_RALT
  )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU),  ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
    [2] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
    [3] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [4] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
    [5] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },

};
#endif
