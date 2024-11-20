#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/monique.jpg"};
    
    for (glm::vec3& color : image.pixels())
    {
        // On divise par 2 les valeurs des couleurs
        color.r = color.r*1/2;
        color.g = color.g*1/2;
        color.b = color.b*1/2;
    }
    image.save("output/" FILE_NAME ".png");
}
