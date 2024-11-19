#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    image.save("output/" FILE_NAME ".png");
}