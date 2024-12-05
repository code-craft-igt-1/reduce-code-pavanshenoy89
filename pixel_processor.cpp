#include "pixel_processor.h"
#include "Image.h" 


// ImageBrightener implementation
ImageBrightener::ImageBrightener(std::shared_ptr<Image> inputImage)
    : m_inputImage(inputImage) {}

void ImageBrightener::ProcessPixel(int pixelIndex) {
    if (m_inputImage->pixels[pixelIndex] > (255 - 25)) {
        ++m_inputImage->attenuatedPixelCount;
        m_inputImage->pixels[pixelIndex] = 255;
    }
    else {
        m_inputImage->pixels[pixelIndex] += 25;
    }
}


// CustomBrightener implementation
CustomBrightener::CustomBrightener(std::shared_ptr<Image> inputImage, std::shared_ptr<Image> imageToAdd)
    : m_inputImage(inputImage), m_imageToAdd(imageToAdd) {}

void CustomBrightener::ProcessPixel(int pixelIndex) {
    if (m_inputImage->pixels[pixelIndex] + m_imageToAdd->pixels[pixelIndex] > 255) {
        ++m_inputImage->attenuatedPixelCount;
        m_inputImage->pixels[pixelIndex] = 255;
    }
    else {
        m_inputImage->pixels[pixelIndex] += m_imageToAdd->pixels[pixelIndex];
    }
}
