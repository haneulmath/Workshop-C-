#include <sil/sil.hpp>
#include <cmath>

struct Lab {float L; float a; float b;};
struct RGB {float r; float g; float b;};

// Fonction pour convertir une composante de couleur de sRGB à Linear RGB
float sRGBToLinear(float c)
{
    if (c <= 0.04045f)
        return c / 12.92f;
    else
        return std::pow((c + 0.055f) / 1.055f, 2.4f);
}

// Fonction pour convertir une couleur de sRGB à Linear RGB
RGB sRGBToLinear(RGB c)
{
    return {sRGBToLinear(c.r), sRGBToLinear(c.g), sRGBToLinear(c.b)};
}


Lab linear_srgb_to_oklab(RGB c) 
{
    float l = 0.4122214708f * c.r + 0.5363325363f * c.g + 0.0514459929f * c.b;
    float m = 0.2119034982f * c.r + 0.6806995451f * c.g + 0.1073969566f * c.b;
    float s = 0.0883024619f * c.r + 0.2817188376f * c.g + 0.6299787005f * c.b;

    float l_ = cbrtf(l);
    float m_ = cbrtf(m);
    float s_ = cbrtf(s);

    return {
        0.2104542553f * l_ + 0.7936177850f * m_ - 0.0040720468f * s_,
        1.9779984951f * l_ - 2.4285922050f * m_ + 0.4505937099f * s_,
        0.0259040371f * l_ + 0.7827717662f * m_ - 0.8086757660f * s_,
    };
}

RGB oklab_to_linear_srgb(Lab c) 
{
    float l_ = c.L + 0.3963377774f * c.a + 0.2158037573f * c.b;
    float m_ = c.L - 0.1055613458f * c.a - 0.0638541728f * c.b;
    float s_ = c.L - 0.0894841775f * c.a - 1.2914855480f * c.b;

    float l = l_ * l_ * l_;
    float m = m_ * m_ * m_;
    float s = s_ * s_ * s_;

    return {
        +4.0767416621f * l - 3.3077115913f * m + 0.2309699292f * s,
        -1.2684380046f * l + 2.6097574011f * m - 0.3413193965f * s,
        -0.0041960863f * l - 0.7034186147f * m + 1.7076147010f * s,
    };
}

// Fonction pour convertir une composante de couleur de Linear RGB à sRGB
float linearToSRGB(float c)
{
    if (c <= 0.0031308f)
        return 12.92f * c;
    else
        return 1.055f * std::pow(c, 1.0f / 2.4f) - 0.055f;
}

// Fonction pour convertir une couleur de Linear RGB à sRGB
RGB linearToSRGB(RGB c)
{
    return {linearToSRGB(c.r), linearToSRGB(c.g), linearToSRGB(c.b)};
}

int main()
{
    sil::Image image{300, 200};

    RGB firstColor = {1.0f, 0.0f, 0.0f}; // Rouge en sRGB
    RGB secondColor = {0.0f, 1.0f, 0.0f}; // Bleu en sRGB

    // Convertir les couleurs de sRGB à Linear RGB
    RGB firstColorLinear = sRGBToLinear(firstColor);
    RGB secondColorLinear = sRGBToLinear(secondColor);

    // Convertir les couleurs de Linear RGB à Oklab
    Lab firstColorOklab = linear_srgb_to_oklab(firstColorLinear);
    Lab secondColorOklab = linear_srgb_to_oklab(secondColorLinear);

    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            float t = static_cast<float>(x) / image.width();
            Lab colorOklab = {
                firstColorOklab.L * (1 - t) + secondColorOklab.L * t,
                firstColorOklab.a * (1 - t) + secondColorOklab.a * t,
                firstColorOklab.b * (1 - t) + secondColorOklab.b * t
            };

            // Convertir de Oklab à Linear RGB
            RGB colorLinearRGB = oklab_to_linear_srgb(colorOklab);

            // Convertir de Linear RGB à sRGB
            RGB colorSRGB = linearToSRGB(colorLinearRGB);

            // Clamper les valeurs pour s'assurer qu'elles sont dans la plage [0, 1]
            colorSRGB.r = std::clamp(colorSRGB.r, 0.0f, 1.0f);
            colorSRGB.g = std::clamp(colorSRGB.g, 0.0f, 1.0f);
            colorSRGB.b = std::clamp(colorSRGB.b, 0.0f, 1.0f);

            image.pixel(x, y) = glm::vec3(colorSRGB.r, colorSRGB.g, colorSRGB.b);
        }
    }

    image.save("output/" FILE_NAME ".png");
}