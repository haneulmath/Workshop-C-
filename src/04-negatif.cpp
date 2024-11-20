#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/monique.jpg"};

    // On inverse les valeurs de toutes les pixels
    for (glm::vec3& color : image.pixels())
    {
        color.r = 1.f - color.r;
        color.g = 1.f - color.g;
        color.b = 1.f - color.b;
    }
    image.save("output/" FILE_NAME ".png");
}