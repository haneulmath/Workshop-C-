#include <sil/sil.hpp>

int main()
{
    // Charge l'image
    sil::Image image{"images/logo.png"};

    // Parcours l'image
    for (int x{0}; x < image.width(); x++)
    {
        // Échange les cannaux rouge et bleu
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec3 color = image.pixel(x, y);
            image.pixel(x, y) = glm::vec3(color.b, color.g, color.r);
        }
    }
    image.save("output/" FILE_NAME ".png");
}