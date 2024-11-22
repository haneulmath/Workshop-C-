#include <sil/sil.hpp>
#include <cmath> 

int main()
{
    // Paramètres de l'image noire
    int width = 500;
    int height = 500;
    sil::Image image(width, height);

    // Création de l'image noire
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            image.pixel(x, y) = glm::vec3(0.0f, 0.2f, 0.8f); 
        }
    }

    // Paramètres du cercle
    int centerX = width / 2;
    int centerY = height / 2;
    int radius = 80;
    int thickness = 5; // Épaisseur du cercle

    // Création du cercle
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int dx = x - centerX;
            int dy = y - centerY;
            float distance = std::sqrt(dx * dx + dy * dy);
            if (distance >= radius - thickness && distance <= radius + thickness)
            {
                image.pixel(x, y) = glm::vec3(1.0f, 1.0f, 1.0f); // Couleur blanche
            }
        }
    }

    image.save("output/" FILE_NAME ".png");
}