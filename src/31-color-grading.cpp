#include <sil/sil.hpp>
#include <algorithm>
#include <iostream>
#include <cmath>

// Structure couleur HSL
struct HSL {
    float h; 
    float s; 
    float l; 
};

// Conversion d'une couleur RGB en HSL
HSL rgbToHsl(const glm::vec3& rgb) {
    float r = rgb.r;
    float g = rgb.g;
    float b = rgb.b;

    float max = std::max({r, g, b});
    float min = std::min({r, g, b});
    float delta = max - min;

    HSL hsl;
    hsl.l = (max + min) / 2.0f;

    if (delta == 0) {
        hsl.h = 0;
        hsl.s = 0;
    } else {
        hsl.s = hsl.l > 0.5f ? delta / (2.0f - max - min) : delta / (max + min);

        if (max == r) {
            hsl.h = (g - b) / delta + (g < b ? 6 : 0);
        } else if (max == g) {
            hsl.h = (b - r) / delta + 2;
        } else {
            hsl.h = (r - g) / delta + 4;
        }

        hsl.h *= 60;
    }

    return hsl;
}

// Conversion d'une couleur HSL en RGB
glm::vec3 hslToRgb(const HSL& hsl) {
    float h = hsl.h / 360.0f;
    float s = hsl.s;
    float l = hsl.l;

    auto hueToRgb = [](float p, float q, float t) {
        if (t < 0) t += 1;
        if (t > 1) t -= 1;
        if (t < 1.0f / 6.0f) return p + (q - p) * 6 * t;
        if (t < 1.0f / 2.0f) return q;
        if (t < 2.0f / 3.0f) return p + (q - p) * (2.0f / 3.0f - t) * 6;
        return p;
    };

    float r, g, b;

    if (s == 0) {
        r = g = b = l; // achromatic
    } else {
        float q = l < 0.5f ? l * (1 + s) : l + s - l * s;
        float p = 2 * l - q;
        r = hueToRgb(p, q, h + 1.0f / 3.0f);
        g = hueToRgb(p, q, h);
        b = hueToRgb(p, q, h - 1.0f / 3.0f);
    }

    return glm::vec3(r, g, b);
}

// Ajustement de la teinte et la saturation d'une couleur HSL
HSL adjustHueSaturation(const HSL& hsl, float hueAdjustment, float saturationAdjustment) {
    HSL adjustedHsl = hsl;
    adjustedHsl.h = std::fmod(hsl.h + hueAdjustment, 360.0f);
    if (adjustedHsl.h < 0) adjustedHsl.h += 360.0f;
    adjustedHsl.s = std::clamp(hsl.s + saturationAdjustment / 100.0f, 0.0f, 1.0f);
    return adjustedHsl;
}

// Application du color grading à une image
void applyColorGrading(sil::Image& image, float hueHighlights, float saturationHighlights, float hueShadows, float saturationShadows, float hueMidtones, float saturationMidtones, float hueGlobal, float saturationGlobal) {
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            glm::vec3& pixel = image.pixel(x, y);
            HSL hsl = rgbToHsl(pixel);

            // Ajuster la teinte et la saturation globales
            hsl = adjustHueSaturation(hsl, hueGlobal, saturationGlobal);

            // Ajuster la teinte et la saturation des hautes lumières
            if (hsl.l > 0.75f) {
                hsl = adjustHueSaturation(hsl, hueHighlights, saturationHighlights);
            }
            // Ajuster la teinte et la saturation des ombres
            else if (hsl.l < 0.25f) {
                hsl = adjustHueSaturation(hsl, hueShadows, saturationShadows);
            }
            // Ajuster la teinte et la saturation des midtones
            else {
                hsl = adjustHueSaturation(hsl, hueMidtones, saturationMidtones);
            }

            pixel = hslToRgb(hsl);

            // Clamper les valeurs pour s'assurer qu'elles sont dans la plage [0, 1]
            pixel.r = std::clamp(pixel.r, 0.0f, 1.0f);
            pixel.g = std::clamp(pixel.g, 0.0f, 1.0f);
            pixel.b = std::clamp(pixel.b, 0.0f, 1.0f);
        }
    }
}

int main() {
    sil::Image image{"images/doggo.jpg"};

    // Ajustements  des valeurs de teinte entre 0 et 360 et valeurs de saturation entre 0 et 100
    float hueHighlights = 200;
    float saturationHighlights = 0;
    float hueShadows = 350; 
    float saturationShadows = 5;
    float hueMidtones = 350; 
    float saturationMidtones = 5; 
    float hueGlobal = 0; 
    float saturationGlobal = 0; 

    applyColorGrading(image, hueHighlights, saturationHighlights, hueShadows, saturationShadows, hueMidtones, saturationMidtones, hueGlobal, saturationGlobal);

    image.save("output/" FILE_NAME ".png");

    return 0;
}