#include <sil/sil.hpp>
#include <chrono>
#include <iostream>


int main() {
    sil::Image image{"images/monique.jpg"};
    
    sil::Image resultat{image.width(), image.height()};
    
    // Informations du kernel
    int kernelTaille = 100;
    std::cout << "Kernel size: " << kernelTaille << std::endl;

    // On traite la taille si non paire
    kernelTaille = kernelTaille + (kernelTaille % 2 == 0);
    const float kernelValeur = 1.0f / (kernelTaille * kernelTaille);
    const int distance = kernelTaille / 2;

    // Démarrage du timer
    auto startTime = std::chrono::high_resolution_clock::now();
    
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            glm::vec3 sum{0.0f};
            
            // On applique la transformation aux pixels du kernel
            for (int ky = -distance; ky <= distance; ky++) {
                for (int kx = -distance; kx <= distance; kx++) {
                    // On calculre les coordonnées de l'image originale avec gestion des bords
                    int originalX = std::clamp(x + kx, 0, image.width() - 1);
                    int originalY = std::clamp(y + ky, 0, image.height() - 1);
                    
                    // Ajouter la valeur du pixel (pondérée par la matrice) à la somme
                    sum += image.pixel(originalX, originalY) * kernelValeur;
                }
            }
            
            // Placer le pixel modifié
            resultat.pixel(x, y) = sum;
        }
    }
    
    // Fin du timer
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Logger le temps de calcul
    std::cout << "Processing completed in " << duration.count() << " ms." << std::endl;

    resultat.save("output/" FILE_NAME ".png");
}