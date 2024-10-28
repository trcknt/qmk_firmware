/* Copyright 2024 Hashikure-engineering
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

#define LAYOUT( \
    K00, K01, K02, K03, K04,           K05, K06, K07, K08, K09, \
    K10, K11, K12, K13, K14,           K15, K16, K17, K18, K19, \
    K20, K21, K22, K23, K24, K34, K35, K25, K26, K27, K28, K29, \
    K30,           K31, K32, K33, K36, K37, K38,           K39 \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09 }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19 }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29 }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39 } \
}

typedef union {
    uint32_t raw;
    struct {
        uint8_t cpi_val        : 5;
        uint8_t scroll_div     : 4;
        uint8_t rotation_ang   : 4;
        uint8_t scroll_h_rev   : 1;
        uint8_t scroll_v_rev   : 1;
        uint8_t scaling_mode   : 1;

    };
} meteorite_config_t;

extern meteorite_config_t meteorite_config;

enum meteorite_keycodes {
    CPI_DEC    = QK_KB_0, //トラックボールのCPIを減少
    CPI_INC    = QK_KB_1, //トラックボールのCPIを増加

    ROT_DEC    = QK_KB_2, //マウスセンサーのＹ軸を反時計回りに10度回転
    ROT_INC    = QK_KB_3, //マウスセンサーのＹ軸を時計回りに10度回転
    SCAL_MODE  = QK_KB_4, //マウスセンサーのスケーリング有効・無効

    SCR_DEC    = QK_KB_5, //スクロールの感度を減少
    SCR_INC    = QK_KB_6, //スクロールの感度を増加

	SCR_H_REV  = QK_KB_7, //水平のスクロール方向を反転
    SCR_V_REV  = QK_KB_8, //垂直のスクロール方向を反転
    SCR_MO     = QK_KB_9, //押している間スクロールモードが有効

	KBC_RST    = QK_KB_10, //設定をリセット
    KBC_SAV    = QK_KB_11, //設定を保存
};

uint16_t meteorite_get_cpi(uint8_t cpi);
uint16_t meteorite_get_scroll_div(uint8_t div);
void meteorite_set_default_config(void);

#ifdef DEBUG
void debug_meteorite_config(meteorite_config_t config);
#endif
