#include <sil/sil.hpp>


int main()
{
    sil::Image image{"images/monique.jpg"};

    std::vector<float> luminosities;

    // stocker les valeurs de luminosité de chaque pixel dans une liste
    for (int y{0}; y < image.height(); y++)
    {
        for (int x{0}; x < image.width(); x++)
        {
            auto pixel = image.pixel(x, y);
            float luminosity = 0.299f * pixel.r + 0.587f * pixel.g + 0.114f * pixel.b;
            luminosities.push_back(luminosity);
        }
    }

    // Récupérer la valeur min et max dans la liste
    float min_luminosity = *std::min_element(luminosities.begin(), luminosities.end());
    float max_luminosity = *std::max_element(luminosities.begin(), luminosities.end());

    for (int y{0}; y < image.height(); y++)
    {
        for (int x{0}; x < image.width(); x++)
        {
            auto pixel = image.pixel(x, y);

            // On normalise chaque pixel 
            // On retranche la valeur minimum à chaque pixel pour que le pixel minimum soit égal à 0 et que les autres valeurs suivent naturellement selon une règle affine
            // On multiplie chaque pixel par la valeur max - min pour que le pixel maximum soit égal à 1 sachant qu'après la transformation précédente on a retiré le minimum à la valeur maximum

            pixel.r = (pixel.r - min_luminosity) / (max_luminosity - min_luminosity);
            pixel.g = (pixel.g - min_luminosity) / (max_luminosity - min_luminosity);
            pixel.b = (pixel.b - min_luminosity) / (max_luminosity - min_luminosity);

            image.pixel(x, y) = pixel;
        }
    }

    image.save("output/" FILE_NAME ".jpg");

    return 0;
}