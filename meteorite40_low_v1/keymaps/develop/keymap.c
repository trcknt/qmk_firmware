/*
Copyright 2024 Hashikure-engineering

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

//combo
enum combos {
  CMB_ENT,
  CMB_TAB,
  CMB_LNG_1,
  CMB_LNG_2,
  CMB_HOME,
  CMB_END,
  CMB_C_LFT,
  CMB_C_RGT
};

const uint16_t PROGMEM enter_combo[]   = {KC_L, KC_MINS, COMBO_END};
const uint16_t PROGMEM tab_combo[]     = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM lang_1_combo[]  = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM lang_2_combo[]  = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM home_combo[]    = {KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM end_combo[]     = {KC_RIGHT, KC_UP, COMBO_END};
const uint16_t PROGMEM c_left_combo[]  = {KC_LEFT, KC_UP, COMBO_END};
const uint16_t PROGMEM c_right_combo[] = {KC_RIGHT, KC_DOWN, COMBO_END};

combo_t key_combos[] = {
  [CMB_ENT]    = COMBO(enter_combo, KC_ENT),
  [CMB_TAB]    = COMBO(tab_combo, KC_TAB),
  [CMB_LNG_1]  = COMBO(lang_1_combo, KC_LANGUAGE_1),
  [CMB_LNG_2]  = COMBO(lang_2_combo, KC_LANGUAGE_2),
  [CMB_HOME]   = COMBO_ACTION(home_combo),
  [CMB_END]    = COMBO_ACTION(end_combo),
  [CMB_C_LFT]  = COMBO_ACTION(c_left_combo),
  [CMB_C_RGT]  = COMBO_ACTION(c_right_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CMB_C_LFT:
      if (pressed) {
        tap_code16(LCMD(KC_LEFT));
      }
      break;
    case CMB_C_RGT:
      if (pressed) {
        tap_code16(LCMD(KC_RIGHT));
      }
      break;
    case CMB_HOME:
      if (pressed) {
        tap_code16(LCMD(KC_UP));
      }
      break;
    case CMB_END:
      if (pressed) {
        tap_code16(LCMD(KC_DOWN));
      }
      break;
  }
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                         KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                         KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , MS_BTN1   , MS_BTN2   , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    LT(4, KC_ESC), KC_NO,MT(MOD_LGUI, KC_TAB), MT(MOD_LSFT, KC_SPC), LT(1, KC_LNG1), LT(5, KC_LNG2), LT(2,KC_ENT), LT(3,KC_BSPC),KC_NO, KC_DEL
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
    _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  , _______  , _______  , _______ ,
    _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  , _______  , _______  , _______ ,
    _______  , _______  , _______  , _______  , _______  , QK_KB_4   , QK_KB_5   , _______  , _______  , _______  , _______  , _______ ,
    _______  ,            _______  , _______  , QK_KB_9  , QK_KB_6   , QK_KB_7   , QK_KB_10  , _______ , _______  ,            _______
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


/*
enum meteorite_keycodes {
    CPI_DEC    = QK_KB_0, //トラックボールのCPIを減少
    CPI_INC    = QK_KB_1, //トラックボールのCPIを増加

    ROT_DEC    = QK_KB_3, //マウスセンサーのＹ軸を反時計回りに10度回転
    ROT_INC    = QK_KB_4, //マウスセンサーのＹ軸を時計回りに10度回転
    SCAL_MOD   = QK_KB_5, //マウスセンサーのスケーリング有効・無効

    SCR_DEC    = QK_KB_6, //スクロールの感度を減少
    SCR_INC    = QK_KB_7, //スクロールの感度を増加

	SCR_H_REV  = QK_KB_8, //水平のスクロール方向を反転
    SCR_V_REV  = QK_KB_9, //垂直のスクロール方向を反転
    SCR_MO     = QK_KB_10, //押している間スクロールモードが有効

	KBC_RST    = QK_KB_11, //設定をリセット
    KBC_SAV    = QK_KB_12, //設定を保存
};
*/
