#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/monique.jpg"};

    int new_width = image.height();
    int new_height = image.width();

    // On créer une image en inversant les dimensions

    sil::Image new_image{new_width, new_height};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            // On prend les coordonnées opposées pour donner la bonne orientation
            int new_x = image.height() - y - 1;
            int new_y = x;

            new_image.pixel(new_x, new_y) = image.pixel(x, y);
        }
    }

    new_image.save("output/" FILE_NAME ".png");

    return 0;
}
