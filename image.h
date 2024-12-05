#pragma once
#include <cstdint>
#include <iostream>

class PixelProcessor;

class Image {
 public:
    Image(uint16_t rows, uint16_t columns);
    ~Image();
    bool imageSizeIsValid();
    void processPixels(PixelProcessor* processor);
    const uint16_t m_rows;
    const uint16_t m_columns;
    uint8_t* pixels;  // max 1k x 1k image
    int attenuatedPixelCount;
};
