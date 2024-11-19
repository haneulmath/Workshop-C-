#include <sil/sil.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/glm.hpp>
#include <cmath>

glm::vec2 vortex(glm::vec2 point, glm::vec2 center_of_rotation, float angle, float strength)
{
    glm::vec2 offset = point - center_of_rotation;
    float distance = glm::length(offset);
    float vortex_angle = angle * distance * strength;
    glm::vec2 rotated_point = glm::vec2{glm::rotate(glm::mat3{1.f}, vortex_angle) * glm::vec3{offset, 0.f}};
    return rotated_point + center_of_rotation;
}

void applyVortexEffect(sil::Image& image, glm::vec2 center_of_rotation, float angle, float strength)
{
    int width = image.width();
    int height = image.height();
    sil::Image result{width, height};

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            glm::vec2 point{x, y};
            glm::vec2 new_point = vortex(point, center_of_rotation, angle, strength);

            if (new_point.x >= 0 && new_point.x < width && new_point.y >= 0 && new_point.y < height)
            {
                result.pixel(x, y) = image.pixel(new_point.x, new_point.y);
            }
        }
    }

    image = result;
}

int main()
{
    sil::Image image{"images/logo.png"};
    glm::vec2 center_of_rotation{image.width() / 2.0f, image.height() / 2.0f};
    float angle = 0.1f; // Pour ajuster l'angle 
    float strength = 1.0f; // Pour ajuster la force du vortex ici

    applyVortexEffect(image, center_of_rotation, angle, strength);

    image.save("output/" FILE_NAME ".png");
}