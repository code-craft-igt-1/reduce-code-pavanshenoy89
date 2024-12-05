#pragma once
#include <memory>

class Image;


// Base interface for pixel processing
class IPixelProcessor {
public:
    virtual ~IPixelProcessor() = default;
    virtual void ProcessPixel(int pixelIndex) = 0;
};


// ImageBrightener class
class ImageBrightener : public IPixelProcessor {
private:
    std::shared_ptr<Image> m_inputImage;

public:
    ImageBrightener(std::shared_ptr<Image> inputImage);
    void ProcessPixel(int pixelIndex) override;
};


// CustomBrightener class
class CustomBrightener : public IPixelProcessor {
private:
    std::shared_ptr<Image> m_inputImage;
    std::shared_ptr<Image> m_imageToAdd;

public:
    CustomBrightener(std::shared_ptr<Image> inputImage, std::shared_ptr<Image> imageToAdd);
    void ProcessPixel(int pixelIndex) override;
};


