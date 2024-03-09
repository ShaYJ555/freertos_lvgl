/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --font E:\Source\Quark\boardsource\I.MXRT1021\RT1021\squareline\assets\font.ttf -o E:\Source\Quark\boardsource\I.MXRT1021\RT1021\squareline\assets\ui_font_font14.c --format lvgl -r 0x20-0x7f --symbols 温湿度亮度九轴设置加速度 --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONT14
#define UI_FONT_FONT14 1
#endif

#if UI_FONT_FONT14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x55, 0x55, 0x3,

    /* U+0022 "\"" */
    0xbf, 0x0,

    /* U+0023 "#" */
    0x49, 0x24, 0xbf, 0x59, 0x65, 0xbf, 0x51, 0x45,
    0x0,

    /* U+0024 "$" */
    0x21, 0x3f, 0x5e, 0x30, 0xf5, 0xff, 0x88, 0x40,

    /* U+0025 "%" */
    0x63, 0x2a, 0x73, 0x41, 0x82, 0xc, 0x36, 0x53,
    0xa6, 0x30,

    /* U+0026 "&" */
    0x38, 0x91, 0x2, 0x6, 0x4c, 0xbf, 0x5c, 0x99,
    0x79, 0x98,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x2d, 0x49, 0x24, 0x4c, 0x80,

    /* U+0029 ")" */
    0xc9, 0x92, 0x49, 0x6a, 0x0,

    /* U+002A "*" */
    0xa7, 0x5c, 0xef, 0x90,

    /* U+002B "+" */
    0x21, 0x9, 0xf2, 0x10, 0x80,

    /* U+002C "," */
    0xfe,

    /* U+002D "-" */
    0xf8,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x4, 0x30, 0x86, 0x10, 0xc2, 0x18, 0x43, 0x8,
    0x0,

    /* U+0030 "0" */
    0x39, 0x38, 0x61, 0x86, 0x18, 0x72, 0x78,

    /* U+0031 "1" */
    0xe, 0x22, 0x22, 0x22, 0x2f,

    /* U+0032 "2" */
    0x76, 0x42, 0x11, 0x88, 0xcc, 0xe7, 0xc0,

    /* U+0033 "3" */
    0x73, 0x20, 0x82, 0x18, 0xc0, 0x82, 0x89, 0xe0,

    /* U+0034 "4" */
    0x0, 0xc3, 0x1c, 0x52, 0x4f, 0xc4, 0x10, 0x40,

    /* U+0035 "5" */
    0xfe, 0x31, 0x8f, 0x4, 0x21, 0x8f, 0x80,

    /* U+0036 "6" */
    0x33, 0x11, 0x8f, 0x46, 0x31, 0x8b, 0x80,

    /* U+0037 "7" */
    0xfc, 0x46, 0x23, 0x11, 0x8c, 0x40,

    /* U+0038 "8" */
    0x74, 0x63, 0xb7, 0x3b, 0x71, 0x8b, 0x80,

    /* U+0039 "9" */
    0x76, 0x63, 0x18, 0xbc, 0x62, 0x31, 0x0,

    /* U+003C "<" */
    0x13, 0x24, 0xc8, 0xc6, 0x31,

    /* U+003D "=" */
    0xf8, 0x1, 0xf0,

    /* U+003E ">" */
    0x86, 0x18, 0x61, 0x99, 0x98, 0x80,

    /* U+003F "?" */
    0x77, 0xe3, 0x10, 0x8c, 0x46, 0x20, 0x0, 0x60,

    /* U+0040 "@" */
    0x31, 0xac, 0x67, 0xae, 0xbb, 0xe0, 0x49, 0xe0,

    /* U+0041 "A" */
    0x18, 0x38, 0x71, 0xa2, 0x44, 0x9f, 0x23, 0x47,
    0x8e, 0x8,

    /* U+0042 "B" */
    0xfa, 0x38, 0x61, 0x8f, 0xe8, 0x61, 0x86, 0x3f,
    0x0,

    /* U+0043 "C" */
    0x39, 0xfc, 0x60, 0x82, 0x8, 0x20, 0x83, 0x37,
    0x80,

    /* U+0044 "D" */
    0xe3, 0xe8, 0xa1, 0x86, 0x18, 0x61, 0x86, 0x2f,
    0x0,

    /* U+0045 "E" */
    0xfc, 0x21, 0x8, 0x7a, 0x10, 0x84, 0x3c,

    /* U+0046 "F" */
    0xfc, 0x21, 0x8, 0x7a, 0x10, 0x84, 0x20,

    /* U+0047 "G" */
    0x39, 0x38, 0x20, 0x82, 0x78, 0x61, 0x85, 0x17,
    0xc0,

    /* U+0048 "H" */
    0x8c, 0x63, 0x18, 0xfe, 0x31, 0x8c, 0x62,

    /* U+0049 "I" */
    0xf9, 0x8, 0x42, 0x10, 0x84, 0x21, 0x3e,

    /* U+004A "J" */
    0x8, 0x42, 0x10, 0x84, 0x21, 0xa, 0x5c,

    /* U+004B "K" */
    0x86, 0x39, 0xac, 0xe3, 0xc9, 0x26, 0x8a, 0x38,
    0x40,

    /* U+004C "L" */
    0x84, 0x21, 0x8, 0x42, 0x10, 0x84, 0x3e,

    /* U+004D "M" */
    0x66, 0xcd, 0x9b, 0xb5, 0x6b, 0xd6, 0xad, 0x5a,
    0x84,

    /* U+004E "N" */
    0x8e, 0x73, 0x9e, 0xd6, 0xf7, 0x9c, 0xe2,

    /* U+004F "O" */
    0x39, 0x28, 0x61, 0x86, 0x18, 0x61, 0x85, 0x27,
    0x0,

    /* U+0050 "P" */
    0xf2, 0x28, 0x61, 0x86, 0x2f, 0x20, 0x82, 0x8,
    0x0,

    /* U+0051 "Q" */
    0x38, 0x4c, 0x84, 0x84, 0x84, 0x84, 0xf4, 0xdc,
    0x78, 0x7,

    /* U+0052 "R" */
    0xf2, 0x38, 0x61, 0x8f, 0xe9, 0xa6, 0x8a, 0x38,
    0x40,

    /* U+0053 "S" */
    0x74, 0xe3, 0xe, 0x38, 0x61, 0xe, 0x5c,

    /* U+0054 "T" */
    0xfc, 0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x82,
    0x0,

    /* U+0055 "U" */
    0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x5c,

    /* U+0056 "V" */
    0x87, 0x1c, 0xd3, 0x49, 0x27, 0x9c, 0x30, 0xc3,
    0x0,

    /* U+0057 "W" */
    0x80, 0xec, 0xf6, 0x7b, 0xad, 0x52, 0xa9, 0xd4,
    0xce, 0x66, 0x31, 0x18, 0x80,

    /* U+0058 "X" */
    0x8e, 0x2d, 0x94, 0x70, 0x87, 0x14, 0xda, 0x28,
    0xc0,

    /* U+0059 "Y" */
    0x87, 0x34, 0x9e, 0x30, 0xc3, 0xc, 0x30, 0xc2,
    0x0,

    /* U+005A "Z" */
    0x7e, 0xc, 0x30, 0x61, 0x83, 0xc, 0x18, 0x60,
    0xc1, 0xf8,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x93, 0x80,

    /* U+005C "\\" */
    0x84, 0x30, 0x84, 0x30, 0x86, 0x10, 0x82, 0x10,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x27, 0x80,

    /* U+005E "^" */
    0xe, 0x10,

    /* U+005F "_" */
    0xf8,

    /* U+0060 "`" */
    0xa4,

    /* U+0061 "a" */
    0x7a, 0x63, 0x18, 0xc6, 0x6f,

    /* U+0062 "b" */
    0x84, 0x21, 0xf, 0x46, 0x31, 0x9f, 0x80,

    /* U+0063 "c" */
    0x76, 0x61, 0x8, 0x42, 0x2e,

    /* U+0064 "d" */
    0x8, 0x20, 0x82, 0x7a, 0x28, 0xa2, 0x99, 0xe0,

    /* U+0065 "e" */
    0x73, 0x68, 0xbe, 0x82, 0x29, 0x9c,

    /* U+0066 "f" */
    0x7a, 0x52, 0x84, 0x79, 0x8, 0x42, 0x10,

    /* U+0067 "g" */
    0x3d, 0x94, 0x51, 0x45, 0x13, 0xc1, 0x9, 0xc0,

    /* U+0068 "h" */
    0x84, 0x21, 0xe8, 0xc6, 0x31, 0x8c, 0x62,

    /* U+0069 "i" */
    0x60, 0x4, 0x44, 0x44, 0x57, 0x60,

    /* U+006A "j" */
    0x10, 0x1, 0x11, 0x11, 0x1f, 0x60,

    /* U+006B "k" */
    0x84, 0x21, 0x2b, 0x73, 0x1c, 0xb4, 0xa4,

    /* U+006C "l" */
    0x92, 0x49, 0x24, 0xbf, 0x0,

    /* U+006D "m" */
    0xff, 0x26, 0x4c, 0x99, 0x32, 0x64, 0xc9,

    /* U+006E "n" */
    0xf4, 0x63, 0x18, 0xc6, 0x31,

    /* U+006F "o" */
    0x39, 0x38, 0x61, 0x86, 0x1c, 0x9e,

    /* U+0070 "p" */
    0x79, 0x94, 0x51, 0x45, 0xb7, 0x90, 0x41, 0x0,

    /* U+0071 "q" */
    0x7f, 0x38, 0xa2, 0x8a, 0x67, 0x82, 0x18, 0x60,

    /* U+0072 "r" */
    0xfa, 0x28, 0xa0, 0x82, 0x8, 0x20,

    /* U+0073 "s" */
    0x7e, 0x50, 0xe1, 0x87, 0xee,

    /* U+0074 "t" */
    0x1, 0x3e, 0x42, 0x10, 0x85, 0x29, 0xc0,

    /* U+0075 "u" */
    0x8c, 0x63, 0x18, 0xc6, 0x2f,

    /* U+0076 "v" */
    0x9e, 0x76, 0xb5, 0x39, 0x8c,

    /* U+0077 "w" */
    0xb6, 0xdd, 0x7d, 0x7d, 0xe7, 0x94,

    /* U+0078 "x" */
    0xc9, 0xe3, 0xc, 0x31, 0xec, 0xb3,

    /* U+0079 "y" */
    0x45, 0x14, 0x51, 0x44, 0xf0, 0x43, 0x8b, 0xc0,

    /* U+007A "z" */
    0xf8, 0xcc, 0x66, 0x33, 0x1f,

    /* U+007B "{" */
    0x34, 0x44, 0x4c, 0xc4, 0x44, 0x60,

    /* U+007C "|" */
    0xff, 0xf0,

    /* U+007D "}" */
    0xc6, 0x22, 0x22, 0x32, 0x22, 0x26,

    /* U+007E "~" */
    0xed, 0xc0,

    /* U+4E5D "九" */
    0x8, 0x3, 0x0, 0x60, 0x7f, 0x81, 0x30, 0x26,
    0xc, 0xc1, 0x18, 0x62, 0x6c, 0x4f, 0x9, 0xe1,
    0xf0,

    /* U+4EAE "亮" */
    0x4, 0x3f, 0xfc, 0xfe, 0x10, 0x43, 0xf8, 0xff,
    0xe0, 0x1d, 0xfb, 0x31, 0x4, 0x61, 0x8c, 0xe0,
    0xf0,

    /* U+52A0 "加" */
    0x20, 0x4, 0x3f, 0xef, 0x95, 0x16, 0xa2, 0x94,
    0x52, 0x8a, 0x51, 0xca, 0x39, 0x7e, 0xe0, 0x4c,
    0x0,

    /* U+5EA6 "度" */
    0x6, 0xf, 0xfd, 0xfe, 0x3f, 0xf4, 0x88, 0x9f,
    0x13, 0xc2, 0xfe, 0x48, 0x99, 0xf2, 0x7f, 0x5c,
    0x70,

    /* U+6E29 "温" */
    0x6f, 0xe3, 0xc2, 0xf, 0xe0, 0xc2, 0x4c, 0x22,
    0xfe, 0x0, 0x2, 0xfe, 0x2a, 0xa2, 0xaa, 0x2a,
    0xa5, 0xff,

    /* U+6E7F "湿" */
    0x6f, 0xe1, 0xc2, 0xf, 0xe0, 0xc2, 0x4c, 0x22,
    0xfe, 0x0, 0x0, 0xaa, 0x2a, 0xa2, 0x28, 0x22,
    0x85, 0xff,

    /* U+7F6E "置" */
    0x7f, 0xe4, 0x92, 0x7f, 0xef, 0xff, 0x1f, 0x83,
    0xc, 0x3f, 0xc3, 0xfc, 0x30, 0xc3, 0xfc, 0x30,
    0xdf, 0xff,

    /* U+8BBE "设" */
    0xcf, 0x8d, 0x90, 0xb2, 0x4, 0x4e, 0x8e, 0xcf,
    0x9b, 0xf3, 0x64, 0x67, 0x8e, 0x60, 0x37, 0xc,
    0x20,

    /* U+8F74 "轴" */
    0x60, 0x85, 0x88, 0xe0, 0x84, 0x7e, 0xe6, 0xbf,
    0xeb, 0x27, 0xf2, 0x7b, 0xfe, 0xb2, 0x6b, 0x26,
    0xb2, 0x7e,

    /* U+901F "速" */
    0x61, 0x3, 0xfe, 0x1, 0x0, 0x7e, 0xf5, 0x26,
    0x7e, 0x67, 0xcf, 0xd6, 0x39, 0x22, 0x10, 0x78,
    0x3d, 0xfe
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 22, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 57, .box_w = 2, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 4, .adv_w = 73, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 6, .adv_w = 106, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 15, .adv_w = 104, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 23, .adv_w = 116, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 33, .adv_w = 127, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 43, .adv_w = 54, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 44, .adv_w = 81, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 49, .adv_w = 70, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 101, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 58, .adv_w = 106, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 63, .adv_w = 61, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 64, .adv_w = 104, .box_w = 5, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 65, .adv_w = 56, .box_w = 2, .box_h = 1, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 66, .adv_w = 106, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 75, .adv_w = 122, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 82, .adv_w = 83, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 87, .adv_w = 107, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 94, .adv_w = 109, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 102, .adv_w = 106, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 110, .adv_w = 110, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 117, .adv_w = 108, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 124, .adv_w = 97, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 110, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 137, .adv_w = 105, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 144, .adv_w = 95, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 102, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 152, .adv_w = 100, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 158, .adv_w = 95, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 166, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 174, .adv_w = 126, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 184, .adv_w = 127, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 193, .adv_w = 122, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 202, .adv_w = 127, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 211, .adv_w = 113, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 218, .adv_w = 113, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 225, .adv_w = 124, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 234, .adv_w = 112, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 241, .adv_w = 107, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 248, .adv_w = 106, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 255, .adv_w = 120, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 264, .adv_w = 103, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 271, .adv_w = 127, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 280, .adv_w = 108, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 287, .adv_w = 122, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 296, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 305, .adv_w = 151, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 315, .adv_w = 114, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 324, .adv_w = 104, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 331, .adv_w = 113, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 340, .adv_w = 103, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 347, .adv_w = 114, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 356, .adv_w = 162, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 369, .adv_w = 114, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 378, .adv_w = 111, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 387, .adv_w = 109, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 397, .adv_w = 76, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 402, .adv_w = 106, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 410, .adv_w = 75, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 415, .adv_w = 87, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 417, .adv_w = 110, .box_w = 5, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 418, .adv_w = 57, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 419, .adv_w = 109, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 424, .adv_w = 108, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 431, .adv_w = 93, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 436, .adv_w = 107, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 444, .adv_w = 113, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 450, .adv_w = 98, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 457, .adv_w = 109, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 465, .adv_w = 106, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 472, .adv_w = 70, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 478, .adv_w = 90, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 484, .adv_w = 105, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 491, .adv_w = 77, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 496, .adv_w = 123, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 503, .adv_w = 95, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 508, .adv_w = 110, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 514, .adv_w = 99, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 522, .adv_w = 110, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 530, .adv_w = 94, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 536, .adv_w = 90, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 541, .adv_w = 89, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 548, .adv_w = 97, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 553, .adv_w = 99, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 558, .adv_w = 112, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 564, .adv_w = 106, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 570, .adv_w = 96, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 578, .adv_w = 91, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 583, .adv_w = 84, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 589, .adv_w = 44, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 591, .adv_w = 76, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 597, .adv_w = 106, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 599, .adv_w = 202, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 616, .adv_w = 202, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 633, .adv_w = 202, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 650, .adv_w = 202, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 667, .adv_w = 202, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 685, .adv_w = 202, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 703, .adv_w = 202, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 721, .adv_w = 202, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 738, .adv_w = 202, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 756, .adv_w = 202, .box_w = 12, .box_h = 12, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_2[] = {
    0x0, 0x51, 0x443, 0x1049, 0x1fcc, 0x2022, 0x3111, 0x3d61,
    0x4117, 0x41c2
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 26, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 60, .range_length = 67, .glyph_id_start = 27,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 20061, .range_length = 16835, .glyph_id_start = 94,
        .unicode_list = unicode_list_2, .glyph_id_ofs_list = NULL, .list_length = 10, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 3,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_font14 = {
#else
lv_font_t ui_font_font14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_FONT14*/

