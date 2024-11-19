#include <sil/sil.hpp>
#include <algorithm>

int main()
{
    sil::Image image{"images/logo.jpeg"};

    sil::Image outputImage = image;

    // Indique le décalage pour chaque canal de couleur
    int redOffset = -30; 
    int blueOffset = -30; 

    // Parcourt chaque pixel de l'image
    for (int y = 0; y < image.height(); ++y)
    {   
        for (int x = 0; x < image.width(); ++x)
        {
            glm::vec3& currentPixel = outputImage.pixel(x, y);

            // Récupère les pixels voisins pour le canal rouge
            int redIndex = std::clamp(x + redOffset, 0, image.width() - 1);
            glm::vec3 rightPixel = image.pixel(redIndex, y);
            currentPixel.r = rightPixel.r;

            // Récupère les pixels voisins pour le canal vert
            currentPixel.g = image.pixel(x, y).g;

            // Récupère les pixels voisins pour le canal bleu
            int blueIndex = std::clamp(x - blueOffset, 0, image.width() - 1);
            glm::vec3 leftPixel = image.pixel(blueIndex, y);
            currentPixel.b = leftPixel.b;
        }
    }

    outputImage.save("output/" FILE_NAME ".png");
}