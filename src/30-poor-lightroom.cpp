#include <sil/sil.hpp>
#include <algorithm>
#include <iostream>

// Fonction pour ajuster les valeurs des pixels
float adjustValue(float value, int adjustment) {
    float factor = adjustment / 100.0f;
    if (adjustment > 0) {
        return value + (1.0f - value) * factor;
    } else {
        return value + value * factor;
    }
}

// Fonction pour ajuster les hautes lumières, les ombres, les blancs et les noirs
void adjustImage(sil::Image& image, int highlights, int shadows, int whites, int blacks) {
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            glm::vec3& pixel = image.pixel(x, y);

            // Ajuster les hautes lumières
            if (pixel.r > 0.5f) pixel.r = adjustValue(pixel.r, highlights);
            if (pixel.g > 0.5f) pixel.g = adjustValue(pixel.g, highlights);
            if (pixel.b > 0.5f) pixel.b = adjustValue(pixel.b, highlights);

            // Ajuster les ombres
            if (pixel.r < 0.5f) pixel.r = adjustValue(pixel.r, shadows);
            if (pixel.g < 0.5f) pixel.g = adjustValue(pixel.g, shadows);
            if (pixel.b < 0.5f) pixel.b = adjustValue(pixel.b, shadows);

            // Ajuster les blancs
            if (pixel.r > 0.9f) pixel.r = adjustValue(pixel.r, whites);
            if (pixel.g > 0.9f) pixel.g = adjustValue(pixel.g, whites);
            if (pixel.b > 0.9f) pixel.b = adjustValue(pixel.b, whites);

            // Ajuster les noirs
            if (pixel.r < 0.1f) pixel.r = adjustValue(pixel.r, blacks);
            if (pixel.g < 0.1f) pixel.g = adjustValue(pixel.g, blacks);
            if (pixel.b < 0.1f) pixel.b = adjustValue(pixel.b, blacks);

            // Clamper les valeurs pour s'assurer qu'elles sont dans la plage [0, 1]
            pixel.r = std::clamp(pixel.r, 0.0f, 1.0f);
            pixel.g = std::clamp(pixel.g, 0.0f, 1.0f);
            pixel.b = std::clamp(pixel.b, 0.0f, 1.0f);
        }
    }
}

int main() {
    sil::Image image{"images/doggo.jpg"};

    // Ajustements : valeurs entre -100 et 100
    int highlights = -10; // Exemple : augmenter les hautes lumières
    int shadows = 10;   // Exemple : diminuer les ombres
    int whites = 10;     // Exemple : augmenter les blancs
    int blacks = -10;    // Exemple : diminuer les noirs

    adjustImage(image, highlights, shadows, whites, blacks);

    image.save("output/" FILE_NAME ".png");

    return 0;
}