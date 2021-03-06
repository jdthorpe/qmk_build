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

#include <qp.h>

typedef enum { DRIVER_FAILED, DRIVER_SUCCESS, DRIVER_UNSUPPORTED } painter_lld_status_t;

///////////////////////////////////////////////////////////////
// Quantum painter image types
typedef struct painter_raw_image_descriptor_t {
    const painter_image_descriptor_t base;
    const uint32_t                   byte_count;  // number of bytes in the image
    const uint8_t *const             image_data;  // pointer to the image data
} painter_raw_image_descriptor_t;

typedef struct painter_compressed_image_descriptor_t {
    const painter_image_descriptor_t base;
    const uint16_t                   chunk_count;      // number of chunks
    const uint16_t                   chunk_size;       // size of the base chunk -- the last one will usually be smaller and needs to be determined from compressed_size
    const uint32_t *const            chunk_offsets;    // offsets within the compressed_data where each chunk starts
    const uint8_t *const             compressed_data;  // pointers to the compressed chunk data
    const uint32_t                   compressed_size;  // length of the compressed chunk data in its entirety
} painter_compressed_image_descriptor_t;

///////////////////////////////////////////////////////////////
// Quantum Painter definitions
typedef painter_lld_status_t (*painter_driver_init_func)(painter_device_t driver, painter_rotation_t rotation);
typedef painter_lld_status_t (*painter_driver_clear_func)(painter_device_t driver);
typedef painter_lld_status_t (*painter_driver_power_func)(painter_device_t driver, bool power_on);
typedef painter_lld_status_t (*painter_driver_viewport_func)(painter_device_t driver, uint16_t left, uint16_t top, uint16_t right, uint16_t bottom);
typedef painter_lld_status_t (*painter_driver_pixdata_func)(painter_device_t driver, const void *pixel_data, uint32_t byte_count);
typedef painter_lld_status_t (*painter_driver_setpixel_func)(painter_device_t driver, uint16_t x, uint16_t y, uint8_t hue, uint8_t sat, uint8_t val);
typedef painter_lld_status_t (*painter_driver_line_func)(painter_device_t driver, uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t hue, uint8_t sat, uint8_t val);
typedef painter_lld_status_t (*painter_driver_rect_func)(painter_device_t driver, uint16_t left, uint16_t top, uint16_t right, uint16_t bottom, uint8_t hue, uint8_t sat, uint8_t val, bool filled);
typedef painter_lld_status_t (*painter_driver_drawimage_func)(painter_device_t device, uint16_t x, uint16_t y, const painter_image_descriptor_t *image);

struct painter_driver_t {
    painter_driver_init_func      init;
    painter_driver_clear_func     clear;
    painter_driver_power_func     power;
    painter_driver_viewport_func  viewport;
    painter_driver_pixdata_func   pixdata;
    painter_driver_setpixel_func  setpixel;
    painter_driver_line_func      line;
    painter_driver_rect_func      rect;
    painter_driver_drawimage_func drawimage;
};
