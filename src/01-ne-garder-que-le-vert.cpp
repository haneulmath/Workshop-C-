#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = 0.f;
        }
    }

    for (glm::vec3& color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }
    image.save("output/" FILE_NAME ".png");
}