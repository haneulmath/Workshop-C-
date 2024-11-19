#include <sil/sil.hpp>

int main()
{
    // Charge l'image
    sil::Image image{"images/logo.png"};

    // Parcours l'image
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = 0.f;
        }
    }

    // Supprime le rouge et le bleu
    for (glm::vec3& color : image.pixels())
    {
        color.r = 0.f; 
        color.b = 0.f;
    }
    image.save("output/" FILE_NAME ".png");
}