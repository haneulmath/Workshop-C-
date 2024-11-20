#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/monique.jpg"};

    // Détermination des nouvelles dimensions
    int new_width = image.height();
    int new_height = image.width();

    // Création de la nouvelle image
    sil::Image new_image{new_width, new_height};

    // Parcours de chaque pixel de l'image
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            // On prend les coordonnées opposées pour donner la bonne orientation
            int new_x = image.height() - y - 1;
            int new_y = x;

            // Attribution du pixel de l'image originale à la nouvelle position dans l'image avec rotation
            new_image.pixel(new_x, new_y) = image.pixel(x, y); // On copie le pixel
        }
    }

    new_image.save("output/" FILE_NAME ".png");

    return 0;
}
