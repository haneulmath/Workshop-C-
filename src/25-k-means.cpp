#include <vector>
#include <glm/glm.hpp>
#include "sil/sil.hpp"
#include <random>

int main() {
    const int k = 5;
    const int maxIterations = 100;
    
    // On charge les pixels de l'image dans une liste
    sil::Image image{"images/monique.jpg"};
    std::vector<glm::vec3> pixels;
    pixels.reserve(image.width() * image.height());
    
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            pixels.push_back(image.pixel(x, y));
        }
    }
    
    // On initialise k centroïds de coordonnées aléatoires
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, pixels.size() - 1);
    
    std::vector<glm::vec3> centroids;
    centroids.reserve(k);
    for (int i = 0; i < k; ++i) {
        centroids.push_back(pixels[dis(gen)]);
    }
    
    std::vector<int> labels(pixels.size());
    
    // Boucle des k-means
    for (int iter = 0; iter < maxIterations; ++iter) {
        bool changed = false;
        
        // Assigner chaque pixel à au pixel centroid le plus proche
        for (size_t i = 0; i < pixels.size(); ++i) {
            float minDist = std::numeric_limits<float>::max();
            int bestCentroid = 0;
            
            for (int j = 0; j < k; ++j) {
                float dist = glm::distance(pixels[i], centroids[j]);
                if (dist < minDist) {
                    minDist = dist;
                    bestCentroid = j;
                }
            }
            
            // Si au moins un pixel change de cluster, on note le changement
            if (bestCentroid != labels[i]) {
                labels[i] = bestCentroid;
                changed = true;
            }
        }
        
        // l'algorithme converge si aucun pixel n'a changé de cluster (on le stoppe)
        if (!changed) break;
        
        // Si un cluster contient des pixels, recalculer les coordonées du centroïd selon la moyenne des coordonnées des pixels qui lui sont associés
        std::vector<glm::vec3> sums(k, glm::vec3(0));
        std::vector<int> counts(k, 0);
        
        for (size_t i = 0; i < pixels.size(); ++i) {
            sums[labels[i]] += pixels[i];
            counts[labels[i]]++;
        }
        
        for (int i = 0; i < k; ++i) {
            if (counts[i] > 0) {
                centroids[i] = sums[i] / static_cast<float>(counts[i]);
            }
        }
    }
    
    // Remplacement des couleurs de l'image par les couleurs des centroïdes
    int i = 0;
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            image.pixel(x, y) = centroids[labels[i++]];
        }
    }
    
    image.save("output/" FILE_NAME ".png");
    return 0;
}