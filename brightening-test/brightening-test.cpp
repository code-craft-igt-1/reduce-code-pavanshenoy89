#include <gtest/gtest.h>
#include <memory>
#include "../pixel_processor.h"

namespace brighteningtest {

class BrighteningTest : public ::testing::Test {
 protected:
    std::shared_ptr<Image> image;
    void SetUp() override {
        image = std::make_shared<Image>(2, 2);
    }
    void TearDown() override {
    }
};

TEST_F(BrighteningTest, BrightensWholeImage) {
    image->pixels[0] = 45; image->pixels[1] = 55;
    image->pixels[2] = 65; image->pixels[3] = 254;

    ImageBrightener brightener(image);
    image->processPixels(&brightener);
    int attenuatedCount = image->attenuatedPixelCount;

    EXPECT_EQ(attenuatedCount, 1);         // Verify the number of attenuated pixels
    EXPECT_EQ(image->pixels[2], 90);      // Verify the expected brightened pixel value
}

TEST_F(BrighteningTest, BrightensWithAnotherImage) {
    image->pixels[0] = 45; image->pixels[1] = 55;
    image->pixels[2] = 65; image->pixels[3] = 75;

    const auto& brighteningImage = std::make_shared<Image>(2, 2);
    brighteningImage->pixels[0] = 0; brighteningImage->pixels[1] = 25;
    brighteningImage->pixels[2] = 0; brighteningImage->pixels[3] = 25;

    CustomBrightener brightener(image, brighteningImage);

    image->processPixels(&brightener);
    int attenuatedCount = image->attenuatedPixelCount;

    EXPECT_EQ(image->pixels[0], 45);      // Verify the left-side pixel is unchanged
    EXPECT_EQ(image->pixels[1], 80);      // Verify the right-side pixel is brightened
    EXPECT_EQ(attenuatedCount, 0);        // Verify no pixels were attenuated
}

}  // namespace brighteningtest

