#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/photo_faible_contraste.jpg"};

    std::vector<float> luminosities;

    for (int y{0}; y < image.height(); y++)
    {
        for (int x{0}; x < image.width(); x++)
        {
            auto pixel = image.pixel(x, y);
            float luminosity = 0.299f * pixel.r + 0.587f * pixel.g + 0.114f * pixel.b;
            luminosities.push_back(luminosity);
        }
    }

    float min_luminosity = *std::min_element(luminosities.begin(), luminosities.end());
    float max_luminosity = *std::max_element(luminosities.begin(), luminosities.end());

    for (int y{0}; y < image.height(); y++)
    {
        for (int x{0}; x < image.width(); x++)
        {
            auto pixel = image.pixel(x, y);

            pixel.r = (pixel.r - min_luminosity) / (max_luminosity - min_luminosity);
            pixel.g = (pixel.g - min_luminosity) / (max_luminosity - min_luminosity);
            pixel.b = (pixel.b - min_luminosity) / (max_luminosity - min_luminosity);

            image.pixel(x, y) = pixel;
        }
    }

    image.save("output/" FILE_NAME ".png");

    return 0;
}