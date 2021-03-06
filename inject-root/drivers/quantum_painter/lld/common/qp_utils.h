/* Copyright 2018-2020 Nick Brassel (@tzarc)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include <color.h>
#include <qp.h>

#ifndef QUANTUM_PAINTER_COMPRESSED_CHUNK_SIZE
#    define QUANTUM_PAINTER_COMPRESSED_CHUNK_SIZE 128
#endif

uint32_t qp_decode(const void* const input_buffer, const uint32_t input_size, void* output_buffer, const uint32_t output_size);

void qp_generate_colour_lookup_table(HSV* lookup_table, int16_t items, int16_t hue_fg, int16_t sat_fg, int16_t val_fg, int16_t hue_bg, int16_t sat_bg, int16_t val_bg);

RGB qp_hsv_to_rgb(HSV hsv);