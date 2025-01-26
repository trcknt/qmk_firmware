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

os_variant_t detected_os = OS_UNSURE;
static bool swap_executed = false;

bool process_detected_host_os_user(os_variant_t os) {
    detected_os = os;
    #ifdef DEBUG
    switch (os) {
        case OS_UNSURE:
            uprintf("Detected OS: Unsure\n");
            break;
        case OS_WINDOWS:
            uprintf("Detected OS: Windows\n");
            break;
        case OS_MACOS:
            uprintf("Detected OS: macOS\n");
            break;
        case OS_LINUX:
            uprintf("Detected OS: Linux\n");
            break;
        default:
            uprintf("Detected OS: Unknown\n");
            break;
    }
    #endif

    return true;
};

void matrix_scan_user(void) {
    if (!swap_executed && detected_os == OS_WINDOWS) {
        keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
        swap_executed = true;
        #ifdef DEBUG
        uprintf("Swap GUI / Ctrl\n");
        #endif
    } else if(!swap_executed && detected_os == OS_MACOS) {
        keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
        swap_executed = true;
        #ifdef DEBUG
        uprintf("Unwap GUI / Ctrl\n");
        #endif
    }
}

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
        switch(detected_os){
            case OS_WINDOWS:
                tap_code(KC_HOME);
                break;
            case OS_MACOS:
                tap_code16(LCMD(KC_LEFT));
                break;
            default:
                break;
        }
      }
      break;
    case CMB_C_RGT:
      if (pressed) {
        switch(detected_os){
            case OS_WINDOWS:
                tap_code(KC_END);
                break;
            case OS_MACOS:
                tap_code16(LCMD(KC_RIGHT));
                break;
            default:
                break;
        }
      }
      break;
    case CMB_HOME:
      if (pressed) {
        switch(detected_os){
            case OS_WINDOWS:
                tap_code16(LCTL(KC_HOME));
                break;
            case OS_MACOS:
                tap_code16(LCMD(KC_UP));
                break;
            default:
                break;
        }
      }
      break;
    case CMB_END:
      if (pressed) {
        switch(detected_os){
            case OS_WINDOWS:
                tap_code16(LCTL(KC_END));
                break;
            case OS_MACOS:
                tap_code16(LCMD(KC_DOWN));
                break;
            default:
                break;
        }
      }
      break;
  }
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                         KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                         KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , MS_BTN1   , MS_BTN2   , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    LT(4,KC_ESC), KC_NO, MT(MOD_LGUI,KC_TAB), MT(MOD_LSFT,KC_SPC),LT(1,KC_LNG1),LT(5,KC_LNG2), LT(2,KC_ENT), LT(3,KC_BSPC), KC_NO, QK_KB_9
  ),

  [1] = LAYOUT(
    KC_EXCLAIM, KC_AT   , KC_HASH  , KC_DLR   , KC_PERC  ,                         KC_NO    , KC_LPRN  , KC_RPRN  , KC_LBRC  , KC_RBRC  ,
    KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_BSLS  , KC_PIPE  ,                         KC_SCLN  , KC_COLN  , KC_QUOT  , KC_DQT   , KC_EQL   ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , _______   , _______   , KC_GRV   , KC_TILD  , KC_LCBR  , KC_RCBR  , KC_PLUS  ,
    _______  ,            _______  , _______  , _______  , _______   , _______   , _______  , _______  , _______  ,              _______
  ),

  [2] = LAYOUT(
    KC_PAST  , KC_7     , KC_8     , KC_9     , KC_PPLS  ,                         KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KC_PSLS  , KC_4     , KC_5     , KC_6     , KC_PMNS  ,                         KC_NO    , KC_LEFT  , KC_UP    , KC_DOWN  , KC_RIGHT ,
    KC_0     , KC_1     , KC_2     , KC_3     , KC_PDOT  , _______   , _______   , KC_NO    ,A(KC_LEFT),A(KC_UP)  ,A(KC_DOWN),A(KC_RIGHT),
    _______  ,            _______  , _______  , _______  , _______   , _______   , _______  , _______  , _______  ,              _______
  ),

  [3] = LAYOUT(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                         KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10  ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                         KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO   ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , _______   , _______   , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO   ,
    _______  ,            _______  , _______  , _______  , _______   , _______   , _______  , _______  , _______  ,              _______
  ),

  [4] = LAYOUT(
    QK_KB_12 , _______  , _______  , _______  , _______  ,                         QK_KB_4  , QK_KB_0  , QK_KB_1  , _______  , _______ ,
    _______  , _______  , _______  , _______  , _______  ,                         _______  , QK_KB_5  , QK_KB_6  , _______  , _______ ,
    _______  , _______  , _______  , _______  , _______  , QK_KB_2   , QK_KB_3   , _______  , QK_KB_7  , QK_KB_8  , _______  , _______ ,
    _______  ,            _______  , _______  , _______  , _______   , _______   , _______  , QK_KB_10 , QK_KB_11 ,            QK_KB_13
  )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLD, MS_WHLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(MS_WHLD, MS_WHLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [2] = { ENCODER_CCW_CW(MS_WHLD, MS_WHLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [3] = { ENCODER_CCW_CW(MS_WHLD, MS_WHLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [4] = { ENCODER_CCW_CW(QK_KB_0, QK_KB_1),  ENCODER_CCW_CW(QK_KB_5, QK_KB_6)  },
};
#endif

