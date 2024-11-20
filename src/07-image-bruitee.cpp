#include <sil/sil.hpp>
#include <cstdlib>
#include <ctime>

int main()
{
    // Initialise le générateur de nombres aléatoires avec l'heure actuelle
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Charge l'image
    sil::Image image{"images/monique.jpg"}; // 
    int totalPixels = image.width() * image.height(); // Nombre total de pixels
    int numPixelsToModify = totalPixels / 1; // Détermine le nombre de pixels à modifier
    
    // Modification des pixels
    for (int i = 0; i < numPixelsToModify; ++i)
    {
        // Sélectionne un pixel aléatoire
        int randomIndex = std::rand() % totalPixels;
        glm::vec3& color = image.pixels()[randomIndex]; 
        // Ajoute une valeur aléatoire entre -0.1 et 0.4 à chaque composante de couleur
        color.r += static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 0.5f) - 0.1f; 
        color.g += static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 0.5f) - 0.1f; 
        color.b += static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 0.5f) - 0.1f;
    }

    image.save("output/" FILE_NAME ".png");
}