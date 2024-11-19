#include <sil/sil.hpp>
#include <cstdlib>
#include <ctime>

int main()
{
    // Initialiser le générateur de nombres aléatoires
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sil::Image image{"images/logo.png"};
    int totalPixels = image.width() * image.height();
    int numPixelsToModify = totalPixels / 1; // Modifier 

    for (int i = 0; i < numPixelsToModify; ++i)
    {
        int randomIndex = std::rand() % totalPixels;
        glm::vec3& color = image.pixels()[randomIndex];
        color.r += static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 0.5f) - 0.1f;
        color.g += static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 0.5f) - 0.1f;
        color.b += static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 0.5f) - 0.1f;
    }

    image.save("output/" FILE_NAME ".png");
}