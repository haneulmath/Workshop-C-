#include <sil/sil.hpp>
#include <algorithm>

int main()
{
    sil::Image image{"images/logo.jpeg"};

    sil::Image outputImage = image;

    int redOffset = -30; 
    int blueOffset = -30; 

    for (int y = 0; y < image.height(); ++y)
    {
        for (int x = 0; x < image.width(); ++x)
        {
            glm::vec3& currentPixel = outputImage.pixel(x, y);

            int redIndex = std::clamp(x + redOffset, 0, image.width() - 1);
            glm::vec3 rightPixel = image.pixel(redIndex, y);
            currentPixel.r = rightPixel.r;

            currentPixel.g = image.pixel(x, y).g;

            int blueIndex = std::clamp(x - blueOffset, 0, image.width() - 1);
            glm::vec3 leftPixel = image.pixel(blueIndex, y);
            currentPixel.b = leftPixel.b;
        }
    }

    outputImage.save("output/" FILE_NAME ".png");
}