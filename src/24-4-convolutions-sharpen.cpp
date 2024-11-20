#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/monique.jpg"};
    sil::Image result{image.width(), image.height()};

    // Modèle du Kernel
    float kernel[3][3] = {
        {0, -1, 0},
        {-1, 5, -1},
        {0, -1, 0}
    };

    // Algorithme de convolution
    for (int x = 1; x < image.width() - 1; x++)
    {
        for (int y = 1; y < image.height() - 1; y++)
        {
            glm::vec3 sum{0.f};
            
            // On applique le kernel à chaque pixels et aux pixels adjacents
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    sum += image.pixel(x + i, y + j) * kernel[i + 1][j + 1];
                }
            }
            
            result.pixel(x, y) = sum;
        }
    }

    for (int x = 0; x < image.width(); x++)
    {
        result.pixel(x, 0) = image.pixel(x, 0);
        result.pixel(x, image.height() - 1) = image.pixel(x, image.height() - 1);
    }
    for (int y = 0; y < image.height(); y++)
    {
        result.pixel(0, y) = image.pixel(0, y);
        result.pixel(image.width() - 1, y) = image.pixel(image.width() - 1, y);
    }

    result.save("output/" FILE_NAME ".png");
    return 0;
}