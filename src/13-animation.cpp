#include <sil/sil.hpp>
#include <gif.h>
#include <cmath>
#include <iostream>

// On utilise la librarie gif.h de Charlie Tangora pour génèrement directement le gif

int main()
{
    const char* filename = "../output/" FILE_NAME ".gif";
    int width = 500;
    int height = 500;
    int radius = 80;
    // On défini une nombre d'images par secondes
    int frameCount = 100;

    GifWriter gif;
    
    if (!GifBegin(&gif, filename, width, height, 10))
    {
        std::cerr << "Impossible de créer le GIF" << std::endl;
        return 1;
    }

    for (int frame = 0; frame < frameCount; ++frame)
    {
        sil::Image image(width, height);
        
        // On rempli l'image de pixels noirs
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                image.pixel(x, y) = glm::vec3(0.0f, 0.0f, 0.0f); // Black
            }
        }

        // On fait verticalement bouger la position du dique de gauche à droite
        int centerX = (frame * width) / (frameCount - 1);
        int centerY = height / 2;

        // On dessine le disque autour du point central
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                int dx = x - centerX;
                int dy = y - centerY;
                float distance = std::sqrt(dx * dx + dy * dy);
                if (std::sqrt(dx * dx + dy * dy) <= radius)
                {
                    image.pixel(x, y) = glm::vec3(1.0f, 1.0f, 1.0f);
                }
            }
        }

        // On converti l'image en format couleur 8-bit pour le gif
        uint8_t* pixels = new uint8_t[width * height * 4];
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                glm::vec3 color = image.pixel(x, y);
                uint8_t grayValue = color.r * 255;
                pixels[(y * width + x) * 4] = grayValue;     // R
                pixels[(y * width + x) * 4 + 1] = grayValue; // G
                pixels[(y * width + x) * 4 + 2] = grayValue; // B
                pixels[(y * width + x) * 4 + 3] = 255;       // A
            }
        }

        // On ajoute les images au gif
        if (!GifWriteFrame(&gif, pixels, width, height, 10))
        {
            delete[] pixels;
            break;
        }
        
        delete[] pixels;
    }

    GifEnd(&gif);

    return 0;
}