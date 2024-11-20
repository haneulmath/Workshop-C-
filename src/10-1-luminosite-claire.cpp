#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/monique.jpg"};
    
    for (glm::vec3& color : image.pixels())
    {
        // On double les valeurs des couleurs
        color.r = color.r*2;
        color.g = color.g*2;
        color.b = color.b*2;
    }
    image.save("output/" FILE_NAME ".png");
}
