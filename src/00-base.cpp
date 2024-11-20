#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/monique.jpg"};

    image.save("output/" FILE_NAME ".png");
}