#include <sil/sil.hpp>

int main()
{
    sil::Image image{300, 200};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float gray = (float)x / image.width();
            image.pixel(x, y) = {gray, gray, gray};
        }
    }

    image.save("output/" FILE_NAME ".png");
}