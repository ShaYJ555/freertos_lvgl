/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: --bpp 1 --size 12 --font E:\Source\Quark\boardsource\I.MXRT1021\RT1021\squareline\assets\GenJyuuGothic.ttf -o E:\Source\Quark\boardsource\I.MXRT1021\RT1021\squareline\assets\ui_font_GenJyuuGothic12.c --format lvgl -r 0x20-0x7f --symbols 加速度角磁力 --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_GENJYUUGOTHIC12
#define UI_FONT_GENJYUUGOTHIC12 1
#endif

#if UI_FONT_GENJYUUGOTHIC12

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xf3, 0xc0,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xb0,

    /* U+0023 "#" */
    0x24, 0x49, 0xf9, 0x42, 0x9f, 0x9a, 0x24, 0x48,

    /* U+0024 "$" */
    0x21, 0x3d, 0x8c, 0x38, 0xe3, 0x9f, 0xc8, 0x40,

    /* U+0025 "%" */
    0x62, 0x12, 0x42, 0x50, 0x4a, 0x66, 0x92, 0x12,
    0x44, 0x48, 0x89, 0x20, 0xc0,

    /* U+0026 "&" */
    0x38, 0x36, 0x1b, 0xf, 0x7, 0x1f, 0xdb, 0x3d,
    0x8e, 0x7f, 0x80,

    /* U+0027 "'" */
    0xff,

    /* U+0028 "(" */
    0x2d, 0xed, 0xb6, 0xcd, 0x90,

    /* U+0029 ")" */
    0x9b, 0x36, 0xdb, 0x7b, 0x40,

    /* U+002A "*" */
    0x6f, 0xf6, 0x0,

    /* U+002B "+" */
    0x30, 0xcf, 0xcc, 0x30, 0xc0,

    /* U+002C "," */
    0xf7, 0x0,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x11, 0x12, 0x22, 0x24, 0x44, 0x48,

    /* U+0030 "0" */
    0x79, 0x2c, 0xf3, 0xcf, 0x3c, 0xd2, 0x78,

    /* U+0031 "1" */
    0x77, 0x8c, 0x63, 0x18, 0xc6, 0xf8,

    /* U+0032 "2" */
    0x79, 0x30, 0xc3, 0x1c, 0xe3, 0x38, 0xfc,

    /* U+0033 "3" */
    0x78, 0x30, 0xc6, 0x30, 0x70, 0xc3, 0x78,

    /* U+0034 "4" */
    0x1c, 0x38, 0xb3, 0x6c, 0xdf, 0xc3, 0x6, 0xc,

    /* U+0035 "5" */
    0x7d, 0x4, 0x1e, 0xc, 0x30, 0xd3, 0x78,

    /* U+0036 "6" */
    0x3d, 0x8c, 0x3e, 0xce, 0x38, 0xd3, 0x38,

    /* U+0037 "7" */
    0xfc, 0x31, 0x86, 0x10, 0xc3, 0xc, 0x30,

    /* U+0038 "8" */
    0x7b, 0x3c, 0xda, 0x3b, 0x7c, 0xf3, 0x78,

    /* U+0039 "9" */
    0x73, 0x2c, 0x73, 0x7c, 0x30, 0xc6, 0x70,

    /* U+003A ":" */
    0xf0, 0x3c,

    /* U+003B ";" */
    0xf0, 0x3d, 0xc0,

    /* U+003C "<" */
    0xd, 0xec, 0x1e, 0xc,

    /* U+003D "=" */
    0xfe, 0x0, 0x7, 0xf0,

    /* U+003E ">" */
    0xc1, 0xe0, 0xde, 0xc0,

    /* U+003F "?" */
    0xf0, 0xc6, 0x73, 0x30, 0xc, 0x60,

    /* U+0040 "@" */
    0xf, 0x86, 0x19, 0x1, 0xa7, 0x9b, 0xb3, 0x66,
    0x6c, 0x94, 0xfc, 0x40, 0xc, 0x0, 0x7c, 0x0,

    /* U+0041 "A" */
    0x18, 0x38, 0x2c, 0x2c, 0x64, 0x7e, 0x46, 0xc2,
    0xc3,

    /* U+0042 "B" */
    0xf9, 0x9b, 0x36, 0x6f, 0x98, 0xf1, 0xe3, 0xfc,

    /* U+0043 "C" */
    0x3c, 0xc3, 0x6, 0xc, 0x18, 0x30, 0x31, 0x3c,

    /* U+0044 "D" */
    0xf9, 0x9b, 0x1e, 0x3c, 0x78, 0xf1, 0xe6, 0xf8,

    /* U+0045 "E" */
    0xff, 0xc, 0x30, 0xfb, 0xc, 0x30, 0xfc,

    /* U+0046 "F" */
    0xff, 0xc, 0x30, 0xfb, 0xc, 0x30, 0xc0,

    /* U+0047 "G" */
    0x3c, 0xc3, 0x6, 0xd, 0xf8, 0xf1, 0xb3, 0x3c,

    /* U+0048 "H" */
    0xc7, 0x8f, 0x1e, 0x3f, 0xf8, 0xf1, 0xe3, 0xc6,

    /* U+0049 "I" */
    0xff, 0xff, 0xc0,

    /* U+004A "J" */
    0x18, 0xc6, 0x31, 0x8c, 0x73, 0xf0,

    /* U+004B "K" */
    0xc7, 0x9b, 0x67, 0x8f, 0x9f, 0x33, 0x63, 0xc6,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xfc,

    /* U+004D "M" */
    0xc3, 0xc3, 0xe7, 0xe7, 0xff, 0xdb, 0xdb, 0xdb,
    0xc3,

    /* U+004E "N" */
    0xc7, 0xcf, 0x9f, 0xbd, 0x7b, 0xf3, 0xe7, 0xc6,

    /* U+004F "O" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66,
    0x3c,

    /* U+0050 "P" */
    0xfd, 0x8f, 0x1e, 0x3c, 0xff, 0xb0, 0x60, 0xc0,

    /* U+0051 "Q" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x7e,
    0x3c, 0x8, 0x7,

    /* U+0052 "R" */
    0xfd, 0x8f, 0x1e, 0x3f, 0xd9, 0x33, 0x63, 0xc6,

    /* U+0053 "S" */
    0x7b, 0x2c, 0x3c, 0x78, 0xf0, 0xe3, 0xf8,

    /* U+0054 "T" */
    0xfe, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30,

    /* U+0055 "U" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xa6, 0x7c,

    /* U+0056 "V" */
    0xc3, 0x8d, 0x1b, 0x26, 0xc5, 0x8f, 0x1c, 0x18,

    /* U+0057 "W" */
    0xc4, 0x69, 0xc9, 0x39, 0x35, 0x66, 0xac, 0xd7,
    0x9e, 0xf1, 0x8c, 0x31, 0x80,

    /* U+0058 "X" */
    0xc5, 0x36, 0x8e, 0x31, 0xe7, 0xb3, 0xc4,

    /* U+0059 "Y" */
    0x87, 0x3c, 0xde, 0x78, 0xc3, 0xc, 0x30,

    /* U+005A "Z" */
    0xfc, 0x71, 0x8e, 0x31, 0x86, 0x30, 0xfc,

    /* U+005B "[" */
    0xfb, 0x6d, 0xb6, 0xdb, 0x70,

    /* U+005C "\\" */
    0xc4, 0x44, 0x62, 0x22, 0x31, 0x11,

    /* U+005D "]" */
    0xed, 0xb6, 0xdb, 0x6d, 0xf0,

    /* U+005E "^" */
    0x23, 0x94, 0xad, 0xc4,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0xb4,

    /* U+0061 "a" */
    0x78, 0x31, 0xdf, 0xcf, 0x37, 0xc0,

    /* U+0062 "b" */
    0xc3, 0xc, 0x3e, 0xcf, 0x3c, 0xf3, 0xcf, 0xe0,

    /* U+0063 "c" */
    0x3b, 0x31, 0x8c, 0x71, 0xe0,

    /* U+0064 "d" */
    0xc, 0x30, 0xdf, 0xcf, 0x3c, 0xf3, 0xcd, 0xd0,

    /* U+0065 "e" */
    0x3c, 0xcd, 0x1f, 0xf4, 0xc, 0xf, 0x0,

    /* U+0066 "f" */
    0x36, 0x6f, 0x66, 0x66, 0x66,

    /* U+0067 "g" */
    0x7f, 0x9b, 0x36, 0x67, 0x98, 0x1f, 0x63, 0xc6,
    0xf8,

    /* U+0068 "h" */
    0xc3, 0xc, 0x3e, 0xcf, 0x3c, 0xf3, 0xcf, 0x30,

    /* U+0069 "i" */
    0xf3, 0xff, 0xf0,

    /* U+006A "j" */
    0x6c, 0x36, 0xdb, 0x6d, 0xfc,

    /* U+006B "k" */
    0xc3, 0xc, 0x33, 0xdb, 0xcf, 0x3e, 0xcf, 0x30,

    /* U+006C "l" */
    0xdb, 0x6d, 0xb6, 0xdc,

    /* U+006D "m" */
    0xff, 0xb3, 0x3c, 0xcf, 0x33, 0xcc, 0xf3, 0x3c,
    0xcc,

    /* U+006E "n" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3c, 0xc0,

    /* U+006F "o" */
    0x38, 0xdb, 0x1e, 0x3c, 0x6d, 0x8e, 0x0,

    /* U+0070 "p" */
    0xbb, 0x3c, 0xf3, 0xcf, 0x3f, 0xb0, 0xc3, 0x0,

    /* U+0071 "q" */
    0x7f, 0x3c, 0xf3, 0xcf, 0x37, 0xc3, 0xc, 0x30,

    /* U+0072 "r" */
    0xfe, 0xcc, 0xcc, 0xc0,

    /* U+0073 "s" */
    0x76, 0x38, 0xe3, 0x8f, 0xc0,

    /* U+0074 "t" */
    0x63, 0x3e, 0xc6, 0x31, 0x8c, 0x38,

    /* U+0075 "u" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x37, 0xc0,

    /* U+0076 "v" */
    0xc6, 0x89, 0xb3, 0x62, 0x85, 0xe, 0x0,

    /* U+0077 "w" */
    0xcc, 0xd3, 0x36, 0xe9, 0xba, 0x7b, 0x8c, 0xe3,
    0x30,

    /* U+0078 "x" */
    0x4d, 0xb3, 0x8e, 0x39, 0xb4, 0xc0,

    /* U+0079 "y" */
    0xc6, 0x89, 0xb3, 0x62, 0x87, 0x6, 0x8, 0x30,
    0xc0,

    /* U+007A "z" */
    0x7c, 0x71, 0x8e, 0x71, 0x87, 0xc0,

    /* U+007B "{" */
    0x76, 0x66, 0x6e, 0xe6, 0x66, 0x67,

    /* U+007C "|" */
    0xff, 0xfc,

    /* U+007D "}" */
    0xc6, 0x66, 0x67, 0x76, 0x66, 0x6e,

    /* U+007E "~" */
    0xe1, 0xc0,

    /* U+529B "力" */
    0x18, 0x6, 0xf, 0xfc, 0x63, 0x18, 0xce, 0x33,
    0xc, 0xc3, 0x60, 0xf0, 0x28, 0x38,

    /* U+52A0 "加" */
    0x40, 0x10, 0xff, 0xa5, 0x29, 0x4a, 0x52, 0x94,
    0xa5, 0x29, 0xca, 0x62, 0xfb, 0xa4,

    /* U+5EA6 "度" */
    0x4, 0xf, 0xfd, 0x22, 0x3f, 0xf4, 0x88, 0x9f,
    0x10, 0x3, 0xfe, 0x4d, 0x98, 0xe2, 0xf7, 0x80,

    /* U+78C1 "磁" */
    0xf4, 0x4e, 0xd9, 0x3f, 0xa2, 0x47, 0xf8, 0xb7,
    0xb5, 0xf6, 0xa6, 0x56, 0xef, 0x75, 0x3f, 0x80,

    /* U+89D2 "角" */
    0x1f, 0x9, 0x87, 0xfd, 0x91, 0x24, 0x4f, 0xf2,
    0x44, 0xff, 0x60, 0x50, 0x14, 0x3c,

    /* U+901F "速" */
    0xc3, 0xf, 0xfc, 0x8c, 0x7, 0xe0, 0xb5, 0xdf,
    0x99, 0xe3, 0x7e, 0x7b, 0x7e, 0x2, 0x7f, 0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 44, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 71, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 110, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 7, .adv_w = 113, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 15, .adv_w = 113, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 23, .adv_w = 185, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 36, .adv_w = 142, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 62, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 48, .adv_w = 73, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 53, .adv_w = 73, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 58, .adv_w = 97, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 61, .adv_w = 113, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 66, .adv_w = 62, .box_w = 2, .box_h = 5, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 68, .adv_w = 71, .box_w = 3, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 69, .adv_w = 62, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 74, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 76, .adv_w = 113, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 83, .adv_w = 113, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 113, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 113, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 113, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 113, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 113, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 113, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 132, .adv_w = 113, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 113, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 62, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 148, .adv_w = 62, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 151, .adv_w = 113, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 155, .adv_w = 113, .box_w = 7, .box_h = 4, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 159, .adv_w = 113, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 163, .adv_w = 99, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 185, .adv_w = 123, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 131, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 202, .adv_w = 126, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 137, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 218, .adv_w = 118, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 225, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 138, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 145, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 248, .adv_w = 63, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 109, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 257, .adv_w = 132, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 265, .adv_w = 111, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 272, .adv_w = 164, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 289, .adv_w = 148, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 298, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 148, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 317, .adv_w = 131, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 325, .adv_w = 120, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 332, .adv_w = 120, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 340, .adv_w = 143, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 119, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 356, .adv_w = 176, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 369, .adv_w = 120, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 376, .adv_w = 111, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 383, .adv_w = 118, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 390, .adv_w = 73, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 395, .adv_w = 74, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 401, .adv_w = 73, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 406, .adv_w = 113, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 410, .adv_w = 109, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 411, .adv_w = 120, .box_w = 2, .box_h = 3, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 412, .adv_w = 113, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 124, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 426, .adv_w = 101, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 431, .adv_w = 124, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 439, .adv_w = 111, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 446, .adv_w = 71, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 451, .adv_w = 115, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 460, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 58, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 471, .adv_w = 59, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 476, .adv_w = 116, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 484, .adv_w = 60, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 488, .adv_w = 185, .box_w = 10, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 123, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 120, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 510, .adv_w = 124, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 518, .adv_w = 124, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 526, .adv_w = 84, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 530, .adv_w = 95, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 535, .adv_w = 81, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 541, .adv_w = 122, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 110, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 554, .adv_w = 166, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 563, .adv_w = 108, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 110, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 578, .adv_w = 98, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 584, .adv_w = 73, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 590, .adv_w = 57, .box_w = 1, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 592, .adv_w = 73, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 598, .adv_w = 113, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 600, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 614, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 628, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 644, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 660, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 674, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x5, 0xc0b, 0x2626, 0x3737, 0x3d84
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 21147, .range_length = 15749, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 6, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 0,
    1, 2, 0, 0, 0, 3, 4, 3,
    5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 6, 6, 0, 0, 0,
    0, 0, 7, 8, 9, 10, 0, 11,
    12, 0, 0, 13, 14, 15, 0, 0,
    10, 16, 10, 17, 18, 19, 20, 21,
    22, 23, 24, 25, 2, 26, 0, 0,
    0, 0, 27, 28, 29, 0, 30, 31,
    32, 33, 0, 0, 34, 0, 33, 33,
    28, 28, 35, 36, 37, 38, 35, 39,
    40, 41, 42, 43, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 1, 2, 0, 0, 0, 0,
    2, 0, 3, 4, 0, 5, 6, 5,
    7, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 8, 8, 0, 0, 0,
    9, 0, 10, 0, 11, 0, 0, 0,
    11, 0, 0, 12, 0, 0, 0, 0,
    11, 0, 11, 0, 13, 14, 15, 16,
    17, 18, 19, 20, 0, 21, 3, 0,
    0, 0, 22, 0, 23, 23, 23, 24,
    25, 0, 26, 27, 0, 0, 28, 28,
    23, 28, 23, 28, 29, 30, 31, 32,
    33, 34, 35, 36, 0, 0, 3, 0,
    0, 0, 0, 0, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, -25, 0, 0, 0,
    0, -14, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 15, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -25, 0, -32, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -22, -5, -18,
    -7, 0, -22, 0, 0, 0, 0, 0,
    0, 0, 7, 0, 0, -4, 0, -11,
    -7, 0, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, -7, -1, -7, -15, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -8, 0, -15, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -5, -3, 0,
    -2, 1, 1, 0, 0, -1, -4, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -7, 0,
    0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -14, 0, -16, 0, 0, 0, 0,
    -7, 0, -2, 0, 0, -8, -2, -3,
    0, -1, -3, 0, -8, 0, 0, -2,
    0, 0, 0, 0, 0, -3, 0, -3,
    -1, 0, -3, 0, 0, 0, 0, -6,
    0, 0, 0, 0, 0, 0, 0, -4,
    -3, -5, 0, -2, -1, -1, -3, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, -3, -2, -2, -3, 0,
    0, 0, 0, 0, 0, -7, 0, 0,
    0, 0, -7, -2, -5, -2, -3, -1,
    -1, -1, -3, -2, 0, 0, 0, 0,
    -4, 0, 0, 0, 0, -3, -2, -3,
    -2, 0, -3, 0, 0, 0, 0, -5,
    0, 0, -1, 0, 0, -2, 0, -10,
    0, -4, 0, -2, 0, -5, -4, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, 0, 0, 0, -18, 0, -9, 0,
    0, -7, -2, -26, -5, 0, 0, -1,
    -1, -5, -3, -6, 0, -7, -3, 0,
    -5, 0, 0, -4, -5, -2, -4, -7,
    -5, -7, -5, -10, 0, 0, 0, -4,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, -4, 0, -3, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, 0, 0, 0,
    0, 0, 0, -8, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -7, 0, -7,
    0, -10, 0, 0, -3, -2, -5, 0,
    -4, -5, -3, -3, -2, 0, -5, 0,
    0, 0, -3, 0, 0, 0, -2, 0,
    0, -7, -2, -7, -5, -5, -7, -3,
    0, -27, 0, -33, 0, -8, 0, 0,
    -10, -1, -7, 0, -5, -23, -7, -15,
    -11, 0, -16, 0, -15, 0, -3, -3,
    -1, 0, 0, 0, 0, -5, -2, -10,
    -7, 0, -10, 0, 0, 0, 0, 0,
    -25, -1, -10, 0, 0, -10, 0, -27,
    -2, -3, 0, 0, 0, -5, -2, -10,
    0, -7, -4, 0, -3, 0, 0, 0,
    -2, 0, 0, 0, 0, -3, 0, -4,
    0, 0, 0, -2, 0, -6, 0, 0,
    0, -2, 0, -2, -3, -4, 0, -3,
    0, -2, -3, -2, 0, -2, -2, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, -3, 0, 0, 0, -2,
    0, 0, 0, 0, 0, 0, 0, -3,
    -3, -4, 0, 0, 0, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, 0, 0, 0, -22, -15, -13, 0,
    0, -8, -5, -23, -5, 0, 0, 0,
    0, -4, -3, -8, 0, -12, -15, -2,
    -12, 0, 0, -8, -11, -2, -8, -5,
    -5, -5, -5, -12, 0, 0, 0, 0,
    -5, 0, -3, 0, 0, -2, 0, -11,
    -2, 0, 0, -2, 0, -2, -3, 0,
    0, -1, 0, 0, -2, 0, 0, 0,
    -1, 0, 0, 0, 0, -3, 0, 0,
    0, 0, 0, 0, -15, -4, -5, 0,
    0, -3, -2, -12, -2, 0, -2, 0,
    0, 0, 0, -4, 0, -7, -4, 0,
    -4, 0, 0, -4, -3, 0, -6, -2,
    -2, -4, -2, -4, 0, 0, 0, 0,
    -7, -1, -1, 0, 0, 0, 0, -9,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, -1, 0, -2, 0, -7, 0, 0,
    0, -1, -5, -3, -3, -4, -2, 0,
    0, 0, 0, 0, 0, -2, -3, -5,
    0, 0, 0, 0, 0, -5, -2, -5,
    -3, -2, -5, -3, 0, 0, 0, 0,
    -22, -15, -9, -7, -3, -3, -3, -19,
    -4, -3, -2, 0, 0, 0, 0, -4,
    0, -15, -10, 0, -11, 0, 0, -8,
    -10, -3, -7, -3, -5, -7, -3, -11,
    0, 0, 0, 0, 0, -5, 0, 0,
    0, 0, -4, -5, -6, 0, -2, 0,
    0, 0, -3, -2, 0, -2, -2, -4,
    -2, 0, 0, 0, 0, -3, -3, -2,
    -2, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -13, -3, -8, -1, 0, -12, 0,
    0, 0, 0, 0, 5, 0, 12, 0,
    0, 0, 0, -4, 0, 0, 1, 0,
    0, 0, 0, -8, 0, 0, 0, 0,
    -6, 0, 0, 0, 0, -5, 0, -5,
    -1, 0, -5, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, -6, 0, 0, 0,
    0, -11, 0, -4, 0, -1, -11, 0,
    -7, -2, 0, -1, 0, 0, 0, 0,
    -1, 0, 0, -1, -1, -5, -1, -2,
    0, 0, 0, 0, 0, -7, 0, 0,
    0, 0, 0, 0, 0, -4, 0, -3,
    0, 0, -5, 0, 0, -2, -5, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, -5,
    0, 0, 0, 0, -3, 0, 0, -4,
    -4, -5, 0, -5, -2, 0, -7, 0,
    -7, -2, 0, -1, -2, 0, 0, 0,
    0, -3, 0, -1, -1, -3, -1, 0,
    1, 8, 7, 0, -12, -3, -1, 0,
    4, 0, 0, 0, 0, 8, 0, 11,
    8, 5, 8, 0, 6, -4, -2, 0,
    -2, 0, -2, 0, -1, 0, -1, 1,
    0, -1, 0, -3, 0, 0, 1, -5,
    0, 0, 5, 0, -9, 0, 0, 0,
    0, -7, 0, 0, 0, 0, -3, 0,
    0, -4, -3, 0, 0, 0, 9, 0,
    0, 0, 0, -1, -1, 0, -1, -3,
    0, 0, 0, -5, 0, 0, 0, 0,
    -3, 0, 0, 0, 0, -5, 0, -2,
    0, 0, -5, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    1, -16, 0, 0, -6, 0, 0, 0,
    0, -9, 0, 0, 0, 0, -3, 0,
    0, -2, -5, 0, -2, 0, -2, 0,
    0, -3, -3, 0, 0, -1, 0, -3,
    0, 0, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, 0, -3,
    0, 0, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -17, -5, -5, 0, 0, -4, 0, -14,
    0, 0, 0, 0, 0, 0, 0, -2,
    1, -6, -2, 0, -2, 0, 0, 0,
    -2, 0, 0, 1, 1, 0, 1, -2,
    0, 0, 0, -5, 0, 2, 0, 0,
    -5, 0, 0, 0, 0, -5, 0, -2,
    0, 0, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, -7, 1, 1, -7, 0, 0, 0,
    0, -3, 0, 0, 0, 0, -1, 0,
    0, -2, -2, 0, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, -3, -4, 0,
    0, -2, 0, -8, 0, -4, 0, -1,
    0, 0, -3, -1, 0, -4, -1, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, -5, 0, 0, 0, 0,
    -16, 0, 0, 0, 0, -1, 0, -6,
    0, -5, 0, -1, 0, -3, -5, 0,
    0, -2, -1, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, 0, 0, -1, 0, -3, 0, 0,
    0, 0, -2, 0, -1, -5, 0, -3,
    0, -2, -6, 0, 0, -2, -5, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    -11, 0, -1, 0, 0, 0, 0, -8,
    0, -4, 0, -1, 0, -1, -3, 0,
    0, -4, -1, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, 0, 0, 0, 0, -5, 0, 0,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, 0, -1, 0, 0, -3, -2, 0,
    0, 0, 0, 0, 0, 0, -2, -1,
    0, 0, -1, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 43,
    .right_class_cnt     = 36,
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
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 1,
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
const lv_font_t ui_font_GenJyuuGothic12 = {
#else
lv_font_t ui_font_GenJyuuGothic12 = {
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



#endif /*#if UI_FONT_GENJYUUGOTHIC12*/

