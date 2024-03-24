#ifndef FOURIER_TRANSFORM_H
#define FOURIER_TRANSFORM_H

#include <cmath>
#include <vector>
#include <complex>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <iostream>

// Generates a sine wave given frequency, amplitude, and number of samples
std::vector<double> generateSineWave(double frequency, double amplitude, int numSamples, double fs);

// Performs the Discrete Fourier Transform on a given signal
std::vector<std::complex<double>> dft(const std::vector<double>& signal);

// Writes the DFT result to a specified file
void writeDFTToFile(const std::vector<std::complex<double>>& dftResult, const std::string& filename);

// Generates a radar signal
std::vector<double> generateRadarSignal(double fc, double pw, double pri, double amplitude, int n_pulses, double fs);

// Write time domain signal to file 
void writeTimeDomainSignalToCSV(const std::vector<double>& signal, const std::string& filename, double fs);

#endif // FOURIER_TRANSFORM_H