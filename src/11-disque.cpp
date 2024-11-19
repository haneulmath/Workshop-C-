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
            image.pixel(x, y) = glm::vec3(0.0f, 0.0f, 0.0f); 
        }
    }

    // Choix des paramètres du disque
    int centerX = width / 2;
    int centerY = height / 2;
    int radius = 80;

    // Création du disque
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int dx = x - centerX;
            int dy = y - centerY;
            if (std::sqrt(dx * dx + dy * dy) <= radius)
            {
                image.pixel(x, y) = glm::vec3(1.0f, 1.0f, 1.0f); 
            }
        }
    }

    image.save("output/" FILE_NAME ".png");
}