#include <sil/sil.hpp>

int main()
{
    sil::Image original{"images/monique.jpg"};

    int repetitionMotif = 5;
    
    // On créer une image vide qui va accueillir le mosaique
    sil::Image mosaic{original.width() * repetitionMotif, original.height() * repetitionMotif};
    
    // On rempli la mosaïque avec des copies miroirs de l'image originale
    for (int y = 0; y < mosaic.height(); y++) {
        for (int x = 0; x < mosaic.width(); x++) {
            // Coordonnées de l'image source avec effet miroir
            int srcX = x % original.width();
            int srcY = y % original.height();
            
            // On inverse horizontalement une image sur deux
            if (((x / original.width()) + (y / original.height())) % 2 == 1) {
                srcX = (original.width() - 1) - srcX;
            }

            if (((y / original.height()) + (x / original.width())) % 2 == 1) {
                srcY = (original.height() - 1) - srcY;
            }
            
            mosaic.pixel(x, y) = original.pixel(srcX, srcY);
        }
    }
    
    mosaic.save("output/" FILE_NAME ".png");
}