#pragma once
#include <cstdint>
#include <iostream>
#include "pixel_processor.h"


class Image {
public:
    Image(uint16_t rows, uint16_t columns) : m_rows(rows), m_columns(columns), attenuatedPixelCount(0) {
        pixels = new uint8_t[m_rows * m_columns];
    }
    ~Image() {
        std::cout << "freeing pixel memory.\n";
        delete[] pixels;
    }
    bool imageSizeIsValid() {
        return m_rows <= 1024 && m_columns <= 1024;
    }
    void processPixels(IPixelProcessor& processor) {
        for (int x = 0; x < m_rows; x++) {
            for (int y = 0; y < m_columns; y++) {
                int pixelIndex = x * m_columns + y;
                processor.ProcessPixel(pixelIndex);
            }
        }
    }

    const uint16_t m_rows;
    const uint16_t m_columns;
    uint8_t* pixels;  // max 1k x 1k image
    int attenuatedPixelCount;
};
