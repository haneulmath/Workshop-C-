#include <sil/sil.hpp>
#include <chrono>
#include <iostream>


sil::Image applyHorizontalBlur(sil::Image const& image, int kernelSize, float kernelValue) {
    sil::Image result{image.width(), image.height()};
    const int distance = kernelSize / 2;
    
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            glm::vec3 sum{0.0f};
            
            // On appliquer le flou horizontalement 
            for (int kx = -distance; kx <= distance; kx++) {
                int originalX = std::clamp(x + kx, 0, image.width() - 1);
                sum += image.pixel(originalX, y) * kernelValue;
            }
            
            result.pixel(x, y) = sum;
        }
    }
    
    return result;
}

sil::Image applyVerticalBlur(sil::Image const& image, int kernelSize, float kernelValue) {
    sil::Image result{image.width(), image.height()};
    const int distance = kernelSize / 2;
    
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            glm::vec3 sum{0.0f};
            
            // On applique le flou vertical
            for (int ky = -distance; ky <= distance; ky++) {
                int originalY = std::clamp(y + ky, 0, image.height() - 1);
                sum += image.pixel(x, originalY) * kernelValue;
            }
            
            result.pixel(x, y) = sum;
        }
    }
    
    return result;
}

int main() {
    sil::Image image{"images/monique.jpg"};
    
    // Information sur le Kernel
    int kernelSize = 100;
    std::cout << "Kernel size: " << kernelSize << std::endl;
    // On traite la taille si non paire
    kernelSize = kernelSize + (kernelSize % 2 == 0);
    
    // On utilise la racine carrée du valeur originale du kernel (filtres séparables)
    const float kernelValue = 1.0f / kernelSize;

    // Démarrage du timer
    auto startTime = std::chrono::high_resolution_clock::now();
    
    // On applique le flou horizontal
    sil::Image horizontalBlur = applyHorizontalBlur(image, kernelSize, kernelValue);
    
    // On applique le flou vertical
    sil::Image finalResult = applyVerticalBlur(horizontalBlur, kernelSize, kernelValue);
    
    // Fin du timer
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Logger le temps de calcul
    std::cout << "Processing completed in " << duration.count() << " ms." << std::endl;

    finalResult.save("output/" FILE_NAME ".png");
}