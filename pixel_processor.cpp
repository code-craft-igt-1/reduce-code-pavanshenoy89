#include "./pixel_processor.h"
#include<memory>

PixelProcessor::PixelProcessor(std::shared_ptr<Image> inputImage)
    : m_inputImage(inputImage) {}

PixelProcessor::~PixelProcessor() = default;

void PixelProcessor::ProcessPixelHelper(int pixelIndex, int brightness) {
    if (m_inputImage->pixels[pixelIndex] + brightness > 255) {
        ++m_inputImage->attenuatedPixelCount;
        m_inputImage->pixels[pixelIndex] = 255;
    } else {
        m_inputImage->pixels[pixelIndex] += brightness;
    }
}

ImageBrightener::ImageBrightener(std::shared_ptr<Image> inputImage)
    : PixelProcessor(inputImage) {}

void ImageBrightener::ProcessPixel(int pixelIndex) {
    ProcessPixelHelper(pixelIndex, 25);
}

CustomBrightener::CustomBrightener(std::shared_ptr<Image> inputImage, const std::shared_ptr<Image> imageToAdd)
    : PixelProcessor(inputImage), m_imageToAdd(imageToAdd) {}

void CustomBrightener::ProcessPixel(int pixelIndex) {
    ProcessPixelHelper(pixelIndex, m_imageToAdd->pixels[pixelIndex]);
}
