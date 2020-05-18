/* Copyright 2018-2020 Nick Brassel (@tzarc)
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Common layers and keys

enum { KC_CONFIG = SAFE_RANGE, TIME_RESET, TIME_EEPRST, KC_LOWER, KC_RAISE, KC_ADJUST, KC_NOMODE, KC_WIDE, KC_SCRIPT, KC_BLOCKS, KC_REGIONAL, KC_AUSSIE, KC_WOWMODE, KC_D3MODE, KEYMAP_SAFE_RANGE };
enum { LAYER_BASE, LAYER_LOWER, LAYER_RAISE, LAYER_ADJUST };

#define KC_TAB_LOWER LT(LAYER_LOWER, KC_TAB)
#define KC_APP_RAISE LT(LAYER_RAISE, KC_APP)
#define KC_CTL_ESC MT(MOD_LCTL, KC_ESC)

#define KC_1PASSWORD C(A(KC_BSLS))

// clang-format off

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fixes

// Handle expansion of the helpers below
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_tkl_ansi_wrapper(...) LAYOUT_tkl_ansi(__VA_ARGS__)
#define LAYOUT_60_ansi_wrapper(...) LAYOUT_60_ansi(__VA_ARGS__)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Layout Helpers: Split 6x4 layouts

////////////////////////////////////////////////////////////////////////////////
// Base layer
//                                               ┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐
#define ____________TZARC_6x4_BASE_R1_L__________ KC_GESC,     KC_1,        KC_2,        KC_3,        KC_4,        KC_5
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_BASE_R2_L__________ KC_TAB,      KC_Q,        KC_W,        KC_E,        KC_R,        KC_T
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_BASE_R3_L__________ KC_CTL_ESC,  KC_A,        KC_S,        KC_D,        KC_F,        KC_G
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_BASE_R4_L__________ KC_LSFT,     KC_Z,        KC_X,        KC_C,        KC_V,        KC_B
//                                               └────────────┴────────────┴────────────┴────────────┴────────────┴────────────┘
//
//                                               ┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐
#define ____________TZARC_6x4_BASE_R1_R__________ KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_BSPC
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_BASE_R2_R__________ KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_DEL
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_BASE_R3_R__________ KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     KC_QUOT
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_BASE_R4_R__________ KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,     KC_SFTENT
//                                               └────────────┴────────────┴────────────┴────────────┴────────────┴────────────┘

////////////////////////////////////////////////////////////////////////////////
// Lower layer
//                                               ┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐
#define ____________TZARC_6x4_LOWER_R1_L_________ KC_F12,      KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_LOWER_R2_L_________ _______,     _______,     KC_UP,       _______,     _______,     KC_1PASSWORD
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_LOWER_R3_L_________ KC_CAPS,     KC_LEFT,     KC_DOWN,     KC_RGHT,     _______,     KC_LBRC
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_LOWER_R4_L_________ _______,     _______,     _______,     _______,     _______,     KC_LCBR
//                                               └────────────┴────────────┴────────────┴────────────┴────────────┴────────────┘
//
//                                               ┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐
#define ____________TZARC_6x4_LOWER_R1_R_________ KC_F6,       KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_LOWER_R2_R_________ KC_P0,       KC_P7,       KC_P8,       KC_P9,       KC_PSLS,     KC_PAST
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_LOWER_R3_R_________ KC_RBRC,     KC_P4,       KC_P5,       KC_P6,       KC_PPLS,     _______
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_LOWER_R4_R_________ KC_RCBR,     KC_P1,       KC_P2,       KC_P3,       KC_PMNS,     _______
//                                               └────────────┴────────────┴────────────┴────────────┴────────────┴────────────┘

////////////////////////////////////////////////////////////////////////////////
// Raise layer
//                                               ┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐
#define ____________TZARC_6x4_RAISE_R1_L_________ KC_F12,      KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_RAISE_R2_L_________ _______,     _______,     KC_UP,       _______,     _______,     _______
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_RAISE_R3_L_________ _______,     KC_LEFT,     KC_DOWN,     KC_RGHT,     _______,     KC_UNDS
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_RAISE_R4_L_________ _______,     _______,     _______,     _______,     _______,     KC_MINS
//                                               └────────────┴────────────┴────────────┴────────────┴────────────┴────────────┘
//
//                                               ┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐
#define ____________TZARC_6x4_RAISE_R1_R_________ KC_F6,       KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_RAISE_R2_R_________ KC_NOMODE,   KC_WIDE,     KC_SCRIPT,   KC_BLOCKS,   KC_REGIONAL, KC_AUSSIE
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_RAISE_R3_R_________ KC_EQL,      _______,     _______,     _______,     _______,     _______
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_RAISE_R4_R_________ KC_PLUS,     _______,     _______,     _______,     _______,     _______
//                                               └────────────┴────────────┴────────────┴────────────┴────────────┴────────────┘

////////////////////////////////////////////////////////////////////////////////
// Adjust layer
//                                               ┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐
#define ____________TZARC_6x4_ADJUST_R1_L________ _______,     _______,     _______,     _______,     _______,     _______
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_ADJUST_R2_L________ KC_MUTE,     KC_VOLU,     KC_MSTP,     KC_MPLY,     KC_MPRV,     KC_MNXT
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_ADJUST_R3_L________ _______,     KC_VOLD,     _______,     _______,     _______,     _______
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_ADJUST_R4_L________ BL_DEC,      BL_INC,      _______,     _______,     _______,     _______
//                                               └────────────┴────────────┴────────────┴────────────┴────────────┴────────────┘
//
//                                               ┌────────────┬────────────┬────────────┬────────────┬────────────┬────────────┐
#define ____________TZARC_6x4_ADJUST_R1_R________ _______,     _______,     _______,     DEBUG,       TIME_EEPRST, TIME_RESET
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_ADJUST_R2_R________ _______,     _______,     _______,     _______,     _______,     _______
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_ADJUST_R3_R________ _______,     RGB_MOD,     RGB_HUI,     RGB_SAI,     RGB_VAI,     RGB_SPI
//                                               ├────────────┼────────────┼────────────┼────────────┼────────────┼────────────┤
#define ____________TZARC_6x4_ADJUST_R4_R________ RGB_TOG,     RGB_RMOD,    RGB_HUD,     RGB_SAD,     RGB_VAD,     RGB_SPD
//                                               └────────────┴────────────┴────────────┴────────────┴────────────┴────────────┘

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Layout Helpers: Standard layout

// Base layer
#define ____________TZARC_BASE_R1_ALPHA_ESC______ KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12
#define ____________TZARC_BASE_R2_ALPHA_GRV______ KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC
#define ____________TZARC_BASE_R3_ALPHA__________ KC_TAB_LOWER, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS
#define ____________TZARC_BASE_R4_ALPHA__________ KC_CTL_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT
#define ____________TZARC_BASE_R5_ALPHA__________ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT
#define ____________TZARC_BASE_R6_ALPHA__________ KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, KC_APP_RAISE, KC_RCTL

#define ____________TZARC_BASE_R2_ALPHA_GESC_____ KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC

#define ____________TZARC_BASE_R1_NAV____________ KC_PSCR, KC_SLCK, KC_PAUS
#define ____________TZARC_BASE_R2_NAV____________ KC_INS, KC_HOME, KC_PGUP
#define ____________TZARC_BASE_R3_NAV____________ KC_DEL, KC_END, KC_PGDN
#define ____________TZARC_BASE_R5_NAV____________ KC_UP
#define ____________TZARC_BASE_R6_NAV____________ KC_LEFT, KC_DOWN, KC_RGHT

// Lower layer
#define ____________TZARC_LOWER_R1_ALPHA_________ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define ____________TZARC_LOWER_R2_ALPHA_NORM____ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define ____________TZARC_LOWER_R3_ALPHA_________ _______, KC_NOMODE, KC_CONFIG, KC_WOWMODE, KC_D3MODE, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE
#define ____________TZARC_LOWER_R4_ALPHA_________ KC_CAPS, KC_WIDE, KC_SCRIPT, KC_BLOCKS, KC_REGIONAL, KC_AUSSIE, _______, _______, _______, _______, _______, _______, _______
#define ____________TZARC_LOWER_R5_ALPHA_________ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define ____________TZARC_LOWER_R6_ALPHA_________ _______, _______, _______, _______, _______, _______, _______, _______

#define ____________TZARC_LOWER_R2_ALPHA_FKEYS___ _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______

#define ____________TZARC_LOWER_R1_NAV___________ _______, _______, _______
#define ____________TZARC_LOWER_R2_NAV___________ _______, _______, _______
#define ____________TZARC_LOWER_R3_NAV___________ _______, _______, _______
#define ____________TZARC_LOWER_R5_NAV___________ _______
#define ____________TZARC_LOWER_R6_NAV___________ _______, _______, _______

// Raise layer
#define ____________TZARC_RAISE_R1_ALPHA_________ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define ____________TZARC_RAISE_R2_ALPHA_________ _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______
#define ____________TZARC_RAISE_R3_ALPHA_________ _______, _______, _______, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, _______, KC_PSLS, KC_PAST, _______
#define ____________TZARC_RAISE_R4_ALPHA_________ KC_CAPS, _______, _______, _______, _______, _______, _______, KC_P4, KC_P5, KC_P6, _______, _______, _______
#define ____________TZARC_RAISE_R5_ALPHA_________ _______, _______, _______, _______, _______, _______, KC_P0, KC_P1, KC_P2, KC_P3, _______, _______
#define ____________TZARC_RAISE_R6_ALPHA_________ _______, _______, _______, _______, _______, _______, _______, _______

#define ____________TZARC_RAISE_R1_NAV___________ _______, _______, _______
#define ____________TZARC_RAISE_R2_NAV___________ _______, _______, _______
#define ____________TZARC_RAISE_R3_NAV___________ _______, _______, _______
#define ____________TZARC_RAISE_R5_NAV___________ _______
#define ____________TZARC_RAISE_R6_NAV___________ _______, _______, _______

// Adjust layer
#define ____________TZARC_ADJUST_R1_ALPHA________ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define ____________TZARC_ADJUST_R2_ALPHA________ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DEBUG, TIME_EEPRST, TIME_RESET
#define ____________TZARC_ADJUST_R3_ALPHA________ _______, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______
#define ____________TZARC_ADJUST_R4_ALPHA________ KC_CAPS, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______, _______
#define ____________TZARC_ADJUST_R5_ALPHA________ _______, BL_DEC, BL_INC, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define ____________TZARC_ADJUST_R6_ALPHA________ _______, _______, _______, _______, _______, _______, _______, _______

#define ____________TZARC_ADJUST_R1_NAV__________ _______, _______, _______
#define ____________TZARC_ADJUST_R2_NAV__________ _______, _______, _______
#define ____________TZARC_ADJUST_R3_NAV__________ _______, _______, _______
#define ____________TZARC_ADJUST_R5_NAV__________ _______
#define ____________TZARC_ADJUST_R6_NAV__________ _______, _______, _______

// clang-format on