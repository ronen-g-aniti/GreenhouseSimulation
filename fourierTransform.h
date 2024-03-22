#ifndef FOURIER_TRANSFORM_H
#define FOURIER_TRANSFORM_H

#include <cmath>
#include <vector>
#include <complex>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>

// Generates a sine wave given frequency, amplitude, and number of samples
std::vector<double> generateSineWave(double frequency, double amplitude, int numSamples);

// Performs the Discrete Fourier Transform on a given signal
std::vector<std::complex<double>> dft(const std::vector<double>& signal);

// Writes the DFT result to a specified file
void writeDFTToFile(const std::vector<std::complex<double>>& dftResult, const std::string& filename);


#endif // FOURIER_TRANSFORM_H