#include <iostream>
#include <complex>
#include <fstream>

void mandelbrot(int width, int height, int max_iterations) {
    double min_x = -2.0;
    double min_y = -1.5;

    std::ofstream outFile("../mandelbrot.ppm");
    outFile << "P3\n" << width << " " << height << "\n255\n";

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double max_y = 1.5;
            double max_x = 1.0;
            double real = min_x + (double(x) / width * (max_x - min_x));
            double imag = min_y + (double(y) / height * (max_y - min_y));

            std::complex<double> c(real, imag);
            std::complex<double> z(0.0, 0.0);
            int iter = 0;

            while (std::abs(z) <= 2.0 && iter < max_iterations) {
                z = z * z + c;
                iter++;
            }

            int red, green, blue;

            if (iter == max_iterations) {
                red = green = blue = 0;
            } else {
                red = (iter * 9) % 256;
                green = (iter * 2) % 256;
                blue = (iter * 5) % 256;
            }
            outFile << red << " " << green << " " << blue << std::endl;
        }
    }
    outFile.close();
}

int main() {
    int width = 1000;
    int height = 1000;
    int max_iterations = 1000;
    mandelbrot(width, height, max_iterations);
    std::cout << "Mandelbrot image saved as 'mandelbrot.ppm'" << std::endl;
    return 0;
}