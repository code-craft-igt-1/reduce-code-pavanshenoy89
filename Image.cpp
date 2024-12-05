#include "image.h"
#include "pixel_processor.h"

Image::Image(uint16_t rows, uint16_t columns) : m_rows(rows), m_columns(columns), attenuatedPixelCount(0) {
    pixels = new uint8_t[m_rows * m_columns];
}

Image::~Image() {
    std::cout << "freeing pixel memory.\n";
    delete[] pixels;
}

bool Image::imageSizeIsValid() {
    return m_rows <= 1024 && m_columns <= 1024;
}

void Image::processPixels(PixelProcessor& processor) {
    for (int x = 0; x < m_rows; x++) {
        for (int y = 0; y < m_columns; y++) {
            int pixelIndex = x * m_columns + y;
            processor.ProcessPixel(pixelIndex);
        }
    }
}
