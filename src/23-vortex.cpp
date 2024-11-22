#include <sil/sil.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/glm.hpp>
#include <cmath>

// Fonction qui applique une transformation de vortex à un point donné
glm::vec2 vortex(glm::vec2 point, glm::vec2 center_of_rotation, float angle, float strength)
{
    // Calcul de l'offset par rapport au centre de rotation
    glm::vec2 offset = point - center_of_rotation;
    // Calcul de la distance entre le point et le centre de rotation
    float distance = glm::length(offset);
    // Calcul de l'angle de rotation proportionnel à la distance et à la force du vortex
    float vortex_angle = angle * distance * strength;
    // Application de la rotation au point
    glm::vec2 rotated_point = glm::vec2{glm::rotate(glm::mat3{1.f}, vortex_angle) * glm::vec3{offset, 0.f}};
    // Retourne le point transformé en ajoutant le centre de rotation
    return rotated_point + center_of_rotation;
}

// Fonction qui applique l'effet de vortex à une image entière
void applyVortexEffect(sil::Image& image, glm::vec2 center_of_rotation, float angle, float strength)
{
    int width = image.width();
    int height = image.height();
    // Création d'une nouvelle image pour stocker le résultat
    sil::Image result{width, height};

    // Parcours de chaque pixel de l'image
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            // Création d'un vecteur pour le point actuel
            glm::vec2 point{x, y};
            // Application de la transformation de vortex au point
            glm::vec2 new_point = vortex(point, center_of_rotation, angle, strength);

            // Vérification que le nouveau point est dans les limites de l'image
            if (new_point.x >= 0 && new_point.x < width && new_point.y >= 0 && new_point.y < height)
            {
                // Copie du pixel de l'image originale à la nouvelle position dans l'image résultat
                result.pixel(x, y) = image.pixel(new_point.x, new_point.y);
            }
        }
    }

    // Remplacement de l'image originale par l'image résultat
    image = result;
}

int main()
{
    sil::Image image{"images/monique.jpg"};
    glm::vec2 center_of_rotation{image.width() / 2.0f, image.height() / 2.0f};
    float angle = 0.1f; // Pour ajuster l'angle 
    float strength = 1.0f; // Pour ajuster la force du vortex ici

    applyVortexEffect(image, center_of_rotation, angle, strength);

    image.save("output/" FILE_NAME ".png");
}