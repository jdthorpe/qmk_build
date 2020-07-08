#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import argparse
import sys
import os
import socket
import re
try:
    from PIL import Image
    from PIL import ImageDraw
    from PIL import ImageFont
    from PIL import ImageChops
except ImportError:
    print("%s depends on the Python Image Library, please install:" % sys.argv[0])
    print("pip3 install Pillow")
    sys.exit(0)

def rescale(val,maxval):
    return int(round(val * maxval / 255.0))

def rgb888_to_rgb565(r,g,b):
    rgb565 = (
        rescale(r, 31) << 11 |
        rescale(g, 63) << 5 |
        rescale(b, 31)
    )
    return rgb565

fileHeader = """\
/* Copyright 2020 QMK
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

/*
 * This file was auto-generated by util/convert_gfx.py!
 */

"""

"""
Convert an image to a packed mono 4bpp byte array
"""
def image_to_mono4bpp(im):
    im = im.convert("RGB")
    image_bytes = im.tobytes("raw","R") # Create a byte array from the red channel of the input image
    image_bytes += b'\0' # Dummy value at the end for alignment
    image_bytes_len = len(image_bytes)

    # Convert 8bpp to packed 4bpp
    mono2array = []
    for x in range(int(image_bytes_len / 2)):
        mono2array.append(
            rescale(image_bytes[x*2+1], 15) << 4 |
            rescale(image_bytes[x*2+0], 15))

    return mono2array

"""
Convert an image to a packed mono 2bpp byte array
"""
def image_to_mono2bpp(im):
    im = im.convert("RGB")
    image_bytes = im.tobytes("raw","R") # Create a byte array from the red channel of the input image
    image_bytes += b'\0\0\0' # Dummy value at the end for alignment
    image_bytes_len = len(image_bytes)

    # Convert 8bpp to packed 2bpp
    mono2array = []
    for x in range(int(image_bytes_len / 4)):
        mono2array.append(
            rescale(image_bytes[x*4+3], 3) << 6 |
            rescale(image_bytes[x*4+2], 3) << 4 |
            rescale(image_bytes[x*4+1], 3) << 2 |
            rescale(image_bytes[x*4+0], 3))

    return mono2array

"""
Convert an image to a packed mono 1bpp byte array
"""
def image_to_mono1bpp(im):
    im = im.convert("RGB")
    image_bytes = im.tobytes("raw","R") # Create a byte array from the red channel of the input image
    image_bytes += b'\0\0\0\0\0\0\0' # Dummy value at the end for alignment
    image_bytes_len = len(image_bytes)

    # Convert 8bpp to packed 1bpp
    mono1array = []
    for x in range(int(image_bytes_len / 8)):
        mono1array.append(
            rescale(image_bytes[x*8+7], 1) << 7 |
            rescale(image_bytes[x*8+6], 1) << 6 |
            rescale(image_bytes[x*8+5], 1) << 5 |
            rescale(image_bytes[x*8+4], 1) << 4 |
            rescale(image_bytes[x*8+3], 1) << 3 |
            rescale(image_bytes[x*8+2], 1) << 2 |
            rescale(image_bytes[x*8+1], 1) << 1 |
            rescale(image_bytes[x*8+0], 1))

    return mono1array

"""
Convert an image to a rgb565 byte array
"""
def image_to_rgb565(im):
    im = im.convert("RGB")
    image_bytes = im.tobytes("raw","RGB") # Create a byte array in 24 bit RGB format from an image
    image_bytes_len = len(image_bytes)

    # Convert 24-bit RGB to 16-bit BGR
    rgb565array = []
    for x in range(int(image_bytes_len / 3)):
        r = image_bytes[x*3+0]
        g = image_bytes[x*3+1]
        b = image_bytes[x*3+2]
        rgb565 = rgb888_to_rgb565(r, g, b)
        rgb565array.append((rgb565 >> 8) & 0xFF)
        rgb565array.append(rgb565 & 0xFF)

    return rgb565array

"""
Measure the size of an image and return the coordinates of the (left, upper, right, lower) bounding box
"""
def measure(im, border=(0,0,0,0)):
    bg = Image.new(im.mode, im.size, border)
    diff = ImageChops.difference(im, bg)
    diff = ImageChops.add(diff, diff, 2.0, -100)
    return diff.getbbox()

"""
Convert the specified font to a pair of .c/.h C language lookup tables in BGR565 format
"""
def convert_graphic_to_c(graphic_fname, output_filename, fmt_rgb565, fmt_4bpp, fmt_2bpp, fmt_1bpp):
    print("Converting %s to gfx-%s.c/h" % (graphic_fname, output_filename))
    sane_name = re.sub(r"[^a-zA-Z0-9]", "_", output_filename)
    graphic_image = Image.open(graphic_fname)

    # Get image dimensions
    (width, height) = graphic_image.size

    # Convert image to rgb565 byte list
    if fmt_rgb565:
        graphic_data = image_to_rgb565(graphic_image)
        newline_counter = int(width * 2)
    elif fmt_4bpp:
        graphic_data = image_to_mono4bpp(graphic_image)
        newline_counter = int(width / 2)
    elif fmt_2bpp:
        graphic_data = image_to_mono2bpp(graphic_image)
        newline_counter = int(width / 4)
    elif fmt_1bpp:
        graphic_data = image_to_mono1bpp(graphic_image)
        newline_counter = int(width / 8)

    # Generate the output filenames
    gfx_source_filename = "gfx-%s.c" % (output_filename)
    gfx_header_filename = "gfx-%s.h" % (output_filename)

    # Generate the C source file
    gfx_source_file = open(gfx_source_filename, "w")
    gfx_source_file.write(fileHeader)

    gfx_source_file.write("/* generated from %s */\n\n" % (graphic_fname))

    gfx_source_file.write("#include \"%s\"\n\n" % (gfx_header_filename))
    gfx_source_file.write("// clang-format off\n\n")

    # Generate image data lookup table
    gfx_source_file.write("const uint8_t gfx_%s[%d] = {\n " % (sane_name, len(graphic_data)))
    count = 0
    for j in graphic_data:
        gfx_source_file.write (" 0b{0:08b}".format(j))
        count += 1
        if count < len(graphic_data):
            gfx_source_file.write(",")
            if (count % newline_counter) == 0: # Place a new line when we reach the same number of pixels as each row
                gfx_source_file.write("\n ")
    gfx_source_file.write("\n};\n\n")
    gfx_source_file.write("// clang-format on\n")
    gfx_source_file.close()

    # Generate the C header file
    gfx_header_file = open(gfx_header_filename, "w")
    gfx_header_file.write(fileHeader)

    gfx_header_file.write("/* generated from %s */\n\n" % (graphic_fname))

    gfx_header_file.write("#pragma once\n\n")
    gfx_header_file.write("// clang-format off\n\n")

    gfx_header_file.write("#include <stdint.h>\n\n")

    gfx_header_file.write("#define GFX_%s_HEIGHT %d\n" % (sane_name.upper(), height))
    gfx_header_file.write("#define GFX_%s_WIDTH  %d\n" % (sane_name.upper(), width))
    gfx_header_file.write("#define GFX_%s_BYTES  %d\n" % (sane_name.upper(), len(graphic_data)))
    if fmt_rgb565:
        gfx_header_file.write("#define GFX_%s_FORMAT IMAGE_FORMAT_RGB565\n\n" % (sane_name.upper()))
    elif fmt_2bpp:
        gfx_header_file.write("#define GFX_%s_FORMAT IMAGE_FORMAT_MONO2BPP\n\n" % (sane_name.upper()))
    elif fmt_4bpp:
        gfx_header_file.write("#define GFX_%s_FORMAT IMAGE_FORMAT_MONO4BPP\n\n" % (sane_name.upper()))
    elif fmt_1bpp:
        gfx_header_file.write("#define GFX_%s_FORMAT IMAGE_FORMAT_MONO1BPP\n\n" % (sane_name.upper()))

    gfx_header_file.write("extern const uint8_t gfx_%s[%d];\n\n" % (sane_name, len(graphic_data)))
    gfx_header_file.write("// clang-format on\n")
    gfx_header_file.close()

def main():
    global args
    parser = argparse.ArgumentParser(description="Convert images to 1bpp or 2bpp for QMK Firmware's quantum_painter")
    parser.add_argument('-o',  '--output',       type=str, required=True, help="The output file name")

    group_fmt = parser.add_mutually_exclusive_group(required=True)
    group_fmt.add_argument('-r',  '--rgb565', help="Output format of RGB565", dest="fmt_rgb565", action="store_true")
    group_fmt.add_argument('-4',  '--4bpp', help="Output format of monochrome 4bpp", dest="fmt_4bpp", action="store_true")
    group_fmt.add_argument('-2',  '--2bpp', help="Output format of monochrome 2bpp", dest="fmt_2bpp", action="store_true")
    group_fmt.add_argument('-1',  '--1bpp', help="Output format of monochrome 1bpp", dest="fmt_1bpp", action="store_true")
    group_fmt.set_defaults(fmt_rgb565=False)
    group_fmt.set_defaults(fmt_4bpp=False)
    group_fmt.set_defaults(fmt_2bpp=False)
    group_fmt.set_defaults(fmt_1bpp=False)

    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('-i',  '--image-file',   type=str, help="The image file to use")

    args, unknown = parser.parse_known_args()

    if args.image_file:

        # Check image file actually exists
        if not os.path.exists(args.image_file):
            print("Can't find file %s" % (args.image_file))
            sys.exit(1)

        convert_graphic_to_c(args.image_file, args.output, args.fmt_rgb565, args.fmt_4bpp, args.fmt_2bpp, args.fmt_1bpp)

if __name__ == "__main__":
    main()