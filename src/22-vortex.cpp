#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    
    image.save("output/" FILE_NAME ".png");
}