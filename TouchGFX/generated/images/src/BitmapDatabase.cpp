// 4.16.1 0xc46fc2ba
// Generated by imageconverter. Please, do not edit!

#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_blue_buttons_round_edge_small[]; // BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID = 0, Size: 170x60 pixels
extern const unsigned char image_blue_buttons_round_edge_small_pressed[]; // BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID = 1, Size: 170x60 pixels
extern const unsigned char image_blue_progressindicators_bg_medium_progress_indicator_bg_square_0_degrees[]; // BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_PROGRESS_INDICATOR_BG_SQUARE_0_DEGREES_ID = 2, Size: 184x20 pixels
extern const unsigned char image_blue_progressindicators_bg_medium_text_progress_bg_square[]; // BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_TEXT_PROGRESS_BG_SQUARE_ID = 3, Size: 84x34 pixels
extern const unsigned char image_blue_progressindicators_fill_tiling_progress_indicator_fill_striped_normal_horizontal[]; // BITMAP_BLUE_PROGRESSINDICATORS_FILL_TILING_PROGRESS_INDICATOR_FILL_STRIPED_NORMAL_HORIZONTAL_ID = 4, Size: 30x40 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] =
{
    { image_blue_buttons_round_edge_small, 0, 170, 60, 11, 4, 148, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 50, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_buttons_round_edge_small_pressed, 0, 170, 60, 11, 4, 148, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 50, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_progressindicators_bg_medium_progress_indicator_bg_square_0_degrees, 0, 184, 20, 0, 0, 184, (uint8_t)(touchgfx::Bitmap::RGB565) >> 3, 20, (uint8_t)(touchgfx::Bitmap::RGB565) & 0x7 },
    { image_blue_progressindicators_bg_medium_text_progress_bg_square, 0, 84, 34, 0, 0, 84, (uint8_t)(touchgfx::Bitmap::RGB565) >> 3, 34, (uint8_t)(touchgfx::Bitmap::RGB565) & 0x7 },
    { image_blue_progressindicators_fill_tiling_progress_indicator_fill_striped_normal_horizontal, 0, 30, 40, 23, 19, 7, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 21, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
}
