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

#include "quantum.h"

// clang-format off
#define LAYOUT_Cyclone( \
     k0101, k0102, k0103, k0104, k0105, k0106, k0107, k0108,               \
     k0201, k0202, k0203, k0204, k0205, k0206, k0207, k0208,               \
     k0301,        k0303, k0304, k0305, k0306,        k0308,               \
     k0401, k0402, k0403, k0404, k0405, k0406, k0407, k0408,               \
     k0501, k0502, k0503, k0504, k0505, k0506, k0507,                      \
     k0601, k0602, k0603, k0604, k0605, k0606, k0607,            k0608,    \
     k0701, k0702, k0703, k0704, k0705, k0706,               k0707, k0708, \
     k0801, k0802, k0803,            k0804,          k0807,      k0808     \
  ) \
  { \
    { k0101, k0102, k0103, k0104, k0105, k0106, k0107, k0108 },            \
    { k0201, k0202, k0203, k0204, k0205, k0206, k0207, k0208 },            \
    { k0301, KC_NO, k0303, k0304, k0305, k0306, KC_NO, k0308 },            \
    { k0401, k0402, k0403, k0404, k0405, k0406, k0407, k0408 },            \
    { k0501, k0502, k0503, k0504, k0505, k0506, k0507, KC_NO },            \
    { k0601, k0602, k0603, k0604, k0605, k0606, k0607, k0608 },            \
    { k0701, k0702, k0703, k0704, k0705, k0706, k0707, k0708 },            \
    { k0801, k0802, k0803, k0804, KC_NO, KC_NO, k0807, k0808 }             \
  }
// clang-format on

void exec_bootloader(void);
