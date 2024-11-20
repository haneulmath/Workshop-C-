#include <sil/sil.hpp>

int main()
{
    // Charge l'image
    sil::Image image{"images/monique.jpg"};

    // Parcours l'image
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec3 color = image.pixel(x, y); // Récupère la couleur du pixel
            image.pixel(x, y) = glm::vec3(color.b, color.g, color.r); // Échange les cannaux rouge et bleu
        }
    }
    image.save("output/" FILE_NAME ".png");
}