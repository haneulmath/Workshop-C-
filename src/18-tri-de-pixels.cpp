#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"

int main()
{
    sil::Image image{"images/monique.jpg"};

    // On récupère tous les pixels de l'image dans un tableau de couleurs
    std::vector<glm::vec3> pixels = image.pixels();

    // On parcours chaque ligne de l'image
    for (int y = 0; y < image.height(); y++) {

        // Générer un nombre aléatoire entre 0 et 3, et appliquer le tri sur la ligne si ce nombre est 0
       if (random_int(0, 3) == 0){
    
            // Trieur de pixels par intensité rouge
            std::sort(pixels.begin() + y * image.width(), pixels.begin() + (y + 1) * image.width(), [](glm::vec3 a, glm::vec3 b) {
                return a.r < b.r;
            });
       }
    }

    // Réinsérer les pixels modifiés dans l'image
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            image.pixel(x, y) = pixels[y * image.width() + x];
        }
    }

    image.save("output/" FILE_NAME ".png");
}