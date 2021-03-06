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

#include <quantum.h>
#include <lzf.h>
#include <qp_utils.h>

uint32_t qp_decode(const void* const input_buffer, const uint32_t input_size, void* output_buffer, const uint32_t output_size) {
    // Use LZF decompressor to decode the chunk data
    return (uint32_t)lzf_decompress(input_buffer, input_size, output_buffer, output_size);
}

void qp_generate_colour_lookup_table(HSV* lookup_table, int16_t items, int16_t hue_fg, int16_t sat_fg, int16_t val_fg, int16_t hue_bg, int16_t sat_bg, int16_t val_bg) {
    // Make sure we take the "shortest" route from one hue to the other
    if ((hue_fg - hue_bg) >= 128) {
        hue_bg += 256;
    } else if ((hue_fg - hue_bg) <= -128) {
        hue_bg -= 256;
    }

    // Interpolate each of the lookup table entries
    for (int16_t i = 0; i < items; ++i) {
        lookup_table[i].h = (uint8_t)((hue_fg - hue_bg) * i / (items - 1) + hue_bg);
        lookup_table[i].s = (uint8_t)((sat_fg - sat_bg) * i / (items - 1) + sat_bg);
        lookup_table[i].v = (uint8_t)((val_fg - val_bg) * i / (items - 1) + val_bg);
    }
}

// this has no CIE curve, intentionally
RGB qp_hsv_to_rgb(HSV hsv) {
    RGB      rgb;
    uint8_t  region, remainder, p, q, t;
    uint16_t h, s, v;

    if (hsv.s == 0) {
        rgb.r = hsv.v;
        rgb.g = hsv.v;
        rgb.b = hsv.v;
        return rgb;
    }

    h = hsv.h;
    s = hsv.s;
    v = hsv.v;

    region    = h * 6 / 255;
    remainder = (h * 2 - region * 85) * 3;

    p = (v * (255 - s)) >> 8;
    q = (v * (255 - ((s * remainder) >> 8))) >> 8;
    t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;

    switch (region) {
        case 6:
        case 0:
            rgb.r = v;
            rgb.g = t;
            rgb.b = p;
            break;
        case 1:
            rgb.r = q;
            rgb.g = v;
            rgb.b = p;
            break;
        case 2:
            rgb.r = p;
            rgb.g = v;
            rgb.b = t;
            break;
        case 3:
            rgb.r = p;
            rgb.g = q;
            rgb.b = v;
            break;
        case 4:
            rgb.r = t;
            rgb.g = p;
            rgb.b = v;
            break;
        default:
            rgb.r = v;
            rgb.g = p;
            rgb.b = q;
            break;
    }

    return rgb;
}
