#include <sil/sil.hpp>
#include <iostream>
#include <complex>

int main()
{
    const int width = 2000;
    const int height = 2000;

    // On créer une imge vide
    sil::Image image{width, height};

    // On défini le nombre de "couches"
    const int precision_max = 100;

    // On centre le graphique sur l'axe des réels et des imaginaires
    const double x_centre = -0.5; 
    const double y_centre = 0.0;
    const double taille = 3.0;

    for (int py = 0; py < height; ++py) {
        for (int px = 0; px < width; ++px) {
            // On map les coordonées du pixel dans le plan complexe
            double x = x_centre + taille * (px - width / 2.0) / width;
            double y = y_centre + taille * (py - height / 2.0) / height;

            // Initialisation du nombre complexe
            std::complex<double> c(x, y);
            std::complex<double> z(0, 0);

            // Vérifier que le point est dans l'ensemble de Mandlebrot et calculer la valeur de l'itération
            int iteration = 0;
            while (iteration < precision_max && std::abs(z) <= 2.0) {
                z = z * z + c;
                iteration++;
            }

            // On défini la couleur du pixel en fonction de l'itération
            if (iteration == precision_max) {
                // Si le pixel est dans l'ensemble, il devient blanc
                image.pixel(px, py) = {1.f, 1.f, 1.f};
            } else {
                // Si le pixel est en dehors, il devient de plus en plus noir au fur et à mesure de l'itération
                float gray_value = static_cast<float>(iteration) / precision_max;
                image.pixel(px, py) = {gray_value, gray_value, gray_value};
            }
        }
    }

    image.save("output/" FILE_NAME ".png");

    return 0;
}
