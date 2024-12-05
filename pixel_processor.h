#pragma once
#include <memory>
#include"image.h"

// Base interface for pixel processing
class PixelProcessor {
    std::shared_ptr<Image> m_inputImage;
public:
    PixelProcessor(std::shared_ptr<Image> inputImage);
    virtual ~PixelProcessor();
    virtual void ProcessPixel(int pixelIndex) = 0;
    virtual void ProcessPixelHelper(int pixelIndex, int brightness);
};


// ImageBrightener class
class ImageBrightener : public PixelProcessor {
public:
    ImageBrightener(std::shared_ptr<Image> inputImage);
    void ProcessPixel(int pixelIndex) override;
};


// CustomBrightener class
class CustomBrightener : public PixelProcessor {
private:
    std::shared_ptr<Image> m_imageToAdd;

public:
    CustomBrightener(std::shared_ptr<Image> inputImage, std::shared_ptr<Image> imageToAdd);
    void ProcessPixel(int pixelIndex) override;
};


