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

    // Paramètres des cercles 
    int centerX = width / 2;
    int centerY = height / 2;
    int centralRadius = 100; 
    int numCircles = 10; // Nombre de cercles
    int thickness = 2; 

    // Fonction de dessin de cercle
    auto drawCircle = [&](int cx, int cy, int radius) {
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                int dx = x - cx;
                int dy = y - cy;
                float distance = std::sqrt(dx * dx + dy * dy);
                if (distance >= radius - thickness && distance <= radius + thickness)
                {
                    image.pixel(x, y) = glm::vec3(1.0f, 1.0f, 1.0f); // Couleur blanche
                }
            }
        }
    };

    // Dessin des autres cercles 
    for (int i = 0; i < numCircles; ++i)
    {
        float angle = 2 * M_PI * i / numCircles; // Angle en radians
        int cx = centerX + static_cast<int>(centralRadius * std::cos(angle)); // Coordonnée x du cercle
        int cy = centerY + static_cast<int>(centralRadius * std::sin(angle)); // Coordonnée y du cercle
        drawCircle(cx, cy, centralRadius); // Dessin du cercle
    }

    image.save("output/" FILE_NAME ".png");
}