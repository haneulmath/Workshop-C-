#include <sil/sil.hpp>

int main()
{
    // Crée une image  
    sil::Image image{300, 200};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            // Assigne une nuance de gris en fonction de la position du pixel en x et y
            float gray = (float)x / image.width(); // x varie de 0 à image.width()
            image.pixel(x, y) = {gray, gray, gray}; // On met le rouge, le vert et le bleu à la même valeur
        }
    }

    image.save("output/" FILE_NAME ".png");
}