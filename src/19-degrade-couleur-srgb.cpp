#include <sil/sil.hpp>

int main()
{
    sil::Image image{300, 200};

    glm::vec3 firstColor = glm::vec3(1.0f, 0.0f, 0.0f);
    glm::vec3 secondColor = glm::vec3(0.0f, 1.0f, 0.0f);   

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float t = static_cast<float>(x) / image.width();
            glm::vec3 color = glm::mix(firstColor, secondColor, t);
            image.pixel(x, y) = color;
        }
    }

    image.save("output/" FILE_NAME ".png");
}