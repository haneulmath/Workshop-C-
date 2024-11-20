#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/monique.jpg"};

    sil::Image tempImage = image;

    // On regénère l'image en inversant les pixels

    for (int x{0}; x < image.width(); x++)
    {        
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y) = tempImage.pixel(tempImage.width() - x - 1, y);
        }

    }

    image.save("output/" FILE_NAME ".png");
}