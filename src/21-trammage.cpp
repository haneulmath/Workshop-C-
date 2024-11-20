#include <sil/sil.hpp>
#include <vector>

int main() {

    sil::Image image{"images/monique.jpg"};
    
    // On créé une matrice de Bayer au départ
    std::vector<std::vector<float>> matrixe = {
        {0.0f, 2.0f}, 
        {3.0f, 1.0f}
    };

    for (int l = 1; l < 3; ++l) {
        int taille = matrixe.size();
        // On génère une nouvelle matrice 4 fois plus grande
        std::vector<std::vector<float>> matrixeNouvelle(taille * 2, std::vector<float>(taille * 2));

        // On remplir la nouvelle matrice avec le motif
        for (int y = 0; y < taille; ++y)
            for (int x = 0; x < taille; ++x) {
                float v = matrixe[y][x] * 4.0f;
                // Répartition des valeurs dans les 4 cases de la nouvelle matrice
                matrixeNouvelle[y][x] = v;
                matrixeNouvelle[y][x + taille] = v + 2.0f;
                matrixeNouvelle[y + taille][x] = v + 3.0f;
                matrixeNouvelle[y + taille][x + taille] = v + 1.0f;
            }
        // Mise à jour de la matrice
        matrixe = matrixeNouvelle;
    }

    // On normalise la matrice
    float valeurMax = matrixe.size() * matrixe.size() - 1.0f;
    for (auto& row : matrixe)
        for (float& val : row)
            val /= valeurMax;

    // Transformation de l'image en noir et blanc avec l'effet de tramage
    int matrixeTaille = matrixe.size();
    for (int y = 0; y < image.height(); y++)
        for (int x = 0; x < image.width(); x++) {
            // On calcul la luminosité moyenne du pixel
            float luminosite = (image.pixel(x, y).r + image.pixel(x, y).g + image.pixel(x, y).b) / 3.0f;
            
            // Récupération de la valeur de la matrice de Bayer pour ce pixel
            float bayer = matrixe[y % matrixeTaille][x % matrixeTaille];
            
            // On définit la couleur (noir ou blanc) du pixel selon la luminosité et la valeur de Bayer
            image.pixel(x, y) = luminosite > 1.0f - bayer ? glm::vec3(1.0f) : glm::vec3(0.0f);
        }
    
    image.save("output/" FILE_NAME ".png");
}