#ifndef _VIDEO_COLORS_H_
#define _VIDEO_COLORS_H_

#define COLOR_BITS 4
#define COLOR_TO_BG(x) (((x) & 0x0F) << COLOR_BITS)

#define COLOR_BRIGHTTEN(x) (((x) & 0x0F) + 0x08)

#define COLOR_BLACK 0x00
#define COLOR_BLUE 0x01
#define COLOR_GREEN 0x02
#define COLOR_CYAN 0x03
#define COLOR_RED 0x04
#define COLOR_PURPLE 0x05
#define COLOR_BROWN 0x06
#define COLOR_WHITE 0x07

#define BACKGROUND_DEFAULT 0x00
#define COLOR_DEFAULT 0x07
#define STYLE_DEFAULT (BACKGROUND_DEFAULT + COLOR_DEFAULT)

#endif