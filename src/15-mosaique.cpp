#include <sil/sil.hpp>

int main()
{
    sil::Image originale{"images/monique.jpg"};

    int repetitionsMotif = 5;
    
    // On créer une image vide qui va accueillir le mosaique
    sil::Image mosaique{originale.width() * repetitionsMotif, originale.height() * repetitionsMotif};
    
    // On remplit la mosaïque avec des copies de l'image originale
    for (int y = 0; y < mosaique.height(); y++) {
        for (int x = 0; x < mosaique.width(); x++) {
            // On répète la longueur et la largeur si dépassée avec %
            int srcX = x % originale.width();
            int srcY = y % originale.height();
            
            mosaique.pixel(x, y) = originale.pixel(srcX, srcY);
        }
    }
    
    mosaique.save("output/" FILE_NAME ".png");
}