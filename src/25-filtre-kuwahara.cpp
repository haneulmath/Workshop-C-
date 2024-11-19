#include <sil/sil.hpp>

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Helper function to calculate mean and variance of a region
void calculateMeanAndVariance(const vector<vector<int>>& image, int startX, int startY, int size, double& mean, double& variance) {
    int sum = 0, sumSquared = 0, pixelCount = 0;

    for (int y = startY; y < startY + size; ++y) {
        for (int x = startX; x < startX + size; ++x) {
            int pixel = image[y][x];
            sum += pixel;
            sumSquared += pixel * pixel;
            ++pixelCount;
        }
    }

    mean = static_cast<double>(sum) / pixelCount;
    variance = static_cast<double>(sumSquared) / pixelCount - mean * mean;
}

// Kuwahara Filter implementation
vector<vector<int>> applyKuwaharaFilter(const vector<vector<int>>& image, int windowSize) {
    if (windowSize % 2 == 0) {
        cerr << "Window size must be odd!" << endl;
        return image;
    }

    int halfWindow = windowSize / 2;
    int height = image.size();
    int width = image[0].size();
    vector<vector<int>> output(height, vector<int>(width, 0));

    // Iterate through the image
    for (int y = halfWindow; y < height - halfWindow; ++y) {
        for (int x = halfWindow; x < width - halfWindow; ++x) {
            double minVariance = numeric_limits<double>::max();
            double bestMean = 0;

            // Calculate statistics for each of the four regions
            for (int region = 0; region < 4; ++region) {
                int startX = x - halfWindow + (region % 2) * halfWindow;
                int startY = y - halfWindow + (region / 2) * halfWindow;
                int size = halfWindow + 1;

                double mean, variance;
                calculateMeanAndVariance(image, startX, startY, size, mean, variance);

                // Find the region with the lowest variance
                if (variance < minVariance) {
                    minVariance = variance;
                    bestMean = mean;
                }
            }

            // Set the center pixel to the mean of the region with the lowest variance
            output[y][x] = static_cast<int>(round(bestMean));
        }
    }

    return output;
}

// Convert a SIL image to a 2D grayscale vector
vector<vector<int>> convertImageToGrayscale(const sil::Image& image) {
    int height = image.height();
    int width = image.width();
    vector<vector<int>> grayscale(height, vector<int>(width, 0));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            auto pixel = image.pixel(x, y); // Assuming pixel returns {r, g, b, a}
            int gray = static_cast<int>(0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b); // Convert to grayscale
            grayscale[y][x] = gray;
        }
    }

    return grayscale;
}

// Convert a 2D grayscale vector back to a SIL image
sil::Image convertGrayscaleToImage(const vector<vector<int>>& grayscale) {
    int height = grayscale.size();
    int width = grayscale[0].size();
    sil::Image output(width, height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int gray = grayscale[y][x];
            output.setPixel(x, y, {gray, gray, gray, 255}); // Set pixel to grayscale with full alpha
        }
    }

    return output;
}

int main() {
    try {
        // Load the input image
        sil::Image image{"images/logo.png"};

        // Convert the image to a grayscale 2D vector
        auto grayscaleImage = convertImageToGrayscale(image);

        // Apply the Kuwahara filter
        int windowSize = 5; // Adjust the window size as needed
        auto filteredGrayscale = applyKuwaharaFilter(grayscaleImage, windowSize);

        // Convert the filtered grayscale image back to a SIL image
        sil::Image filteredImage = convertGrayscaleToImage(filteredGrayscale);

        // Save the output image
        filteredImage.save("output/filtered_logo.png");

        cout << "Filtered image saved as output/filtered_logo.png" << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
