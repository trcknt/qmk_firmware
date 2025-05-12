// Copyright 2024 Hashikure-engineering
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
      KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                         KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
      KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                         KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
      KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , MS_BTN1   , MS_BTN2   , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
      LT(4, KC_ESC), KC_NO,MT(MOD_LGUI, KC_TAB), MT(MOD_LSFT, KC_SPC), LT(1, KC_LNG1), LT(5, KC_LNG2), LT(2,KC_ENT), LT(3,KC_BSPC),KC_NO, QK_KB_9
    ),

    [1] = LAYOUT(
      KC_EXCLAIM, KC_AT   , KC_HASH  , KC_DLR   , KC_PERC  ,                         KC_NO    , KC_LPRN  , KC_RPRN  , KC_LBRC  , KC_RBRC  ,
      KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_BSLS  , KC_PIPE  ,                         KC_SCLN  , KC_COLN  , KC_QUOT  , KC_DQT   , KC_EQL   ,
      KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , _______   , _______   , KC_GRV   , KC_TILD  , KC_LCBR  , KC_RCBR  , KC_PLUS  ,
      _______  ,            _______  , _______  , _______  , _______   , _______   , _______  , _______  , _______  ,            _______
    ),

    [2] = LAYOUT(
      KC_PAST  , KC_7     , KC_8     , KC_9     , KC_PPLS  ,                         KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
      KC_PSLS  , KC_4     , KC_5     , KC_6     , KC_PMNS  ,                         KC_NO    , KC_LEFT  , KC_UP    , KC_DOWN  , KC_RIGHT ,
      KC_0     , KC_1     , KC_2     , KC_3     , KC_PDOT  , _______   , _______   , KC_NO    ,A(KC_LEFT),A(KC_UP)  ,A(KC_DOWN),A(KC_RIGHT),
      _______  ,            _______  , _______  , _______  , _______   , _______   , _______  , _______  , _______  ,            _______
    ),

    [3] = LAYOUT(
      KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                         KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10  ,
      KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                         KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO   ,
      KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , _______   , _______   , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO   ,
      _______  ,            _______  , _______  , _______  , _______   , _______   , _______  , _______  , _______  ,            _______
    ),

    [4] = LAYOUT(
      QK_KB_10 , _______  , _______  , _______  , _______  ,                         QK_KB_4  , _______  , _______  , _______  , QK_KB_11 ,
      _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  , _______  , _______  , _______ ,
      _______  , _______  , _______  , _______  , _______  , QK_KB_2   , QK_KB_3   , _______  , _______  , _______  , _______  , _______ ,
      _______  ,            QK_KB_0  , QK_KB_1  , _______  , QK_KB_7   , QK_KB_8   , _______  , QK_KB_5  , QK_KB_6  ,            _______
    ),

    [5] = LAYOUT(
      _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  , _______  , _______  , _______ ,
      _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  , _______  , _______  , _______ ,
      _______  , _______  , _______  , _______  , _______  , _______   , _______   , _______  , _______  , _______  , _______  , _______ ,
      _______  ,            _______  , _______  , _______  , _______   , _______   , _______  , _______  , _______  ,            _______
    )
  };


  #if defined(ENCODER_MAP_ENABLE)
  const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
      [0] = { ENCODER_CCW_CW(MS_WHLD, MS_WHLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
      [1] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU),  ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
      [2] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
      [3] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
      [4] = { ENCODER_CCW_CW(QK_KB_0, QK_KB_1),  ENCODER_CCW_CW(QK_KB_6, QK_KB_7)  },
      [5] = { ENCODER_CCW_CW(KC_NO, KC_NO),  ENCODER_CCW_CW(KC_NO, KC_NO) },
  };
  #endif
