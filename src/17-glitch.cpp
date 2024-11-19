#include <sil/sil.hpp>
#include <cstdlib>
#include <ctime> 

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 

    sil::Image image{"images/robi.jpeg"};
    int width = image.width();
    int height = image.height();

    int numGlitches = 75; 

    for (int i = 0; i < numGlitches; ++i)
    {   
        int rectWidth = std::rand() % (width / 10) + 1; 
        int rectHeight = std::rand() % (height / 50) + 1; 
        
        int x1 = std::rand() % (width - rectWidth);
        int y1 = std::rand() % (height - rectHeight);
        int x2 = std::rand() % (width - rectWidth);
        int y2 = std::rand() % (height - rectHeight);

        for (int y = 0; y < rectHeight; ++y)
        {
            for (int x = 0; x < rectWidth; ++x)
            {
                glm::vec3 temp = image.pixel(x1 + x, y1 + y);
                image.pixel(x1 + x, y1 + y) = image.pixel(x2 + x, y2 + y);
                image.pixel(x2 + x, y2 + y) = temp; // 
            }
        }
    }

    image.save("output/" FILE_NAME ".png");
}