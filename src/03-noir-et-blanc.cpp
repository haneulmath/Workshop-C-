#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/monique.jpg"};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = 0.f;
        }
    }

    // Convertit chaque pixel en nuance de gris
    for (glm::vec3& color : image.pixels())
    {
        float gray = (color.r + color.g + color.b) / 3.f;
        color.r = gray;
        color.g = gray;
        color.b = gray;
    }
    
    image.save("output/" FILE_NAME ".png");
}