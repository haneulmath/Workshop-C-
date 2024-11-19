#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};

    for (glm::vec3& color : image.pixels())
    {
        color.r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        color.g = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        color.b = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    }

    image.save("output/" FILE_NAME ".png");
}