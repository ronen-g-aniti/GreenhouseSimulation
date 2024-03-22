// GreenhouseSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Environment.h"
#include "Radar.h"
#include "FourierTransform.h"

int main()
{
	Environment env;
	env.reportStatus();
	env.simulateSensorReadings();
	env.reportStatus();
	env.updateConditions(2.0, -5.0);
	env.reportStatus();

    double frequency1 = 10.0; // Frequency of the sine wave in Hz
    double amplitude1 = 5.0; // Amplitude of the sine wave
    int numSamples1 = 1000; // Number of samples in the signal

    std::vector<double> signal1 = generateSineWave(frequency1, amplitude1, numSamples1);
    
    double frequency2 = 40.0; // Frequency of the sine wave in Hz
    double amplitude2 = 5.0; // Amplitude of the sine wave
    int numSamples2 = 1000; // Number of samples in the signal

    std::vector<double> signal2 = generateSineWave(frequency2, amplitude2, numSamples2);

    std::vector<double> signal(numSamples1);
    for (int i = 0; i < numSamples1; ++i) {
        signal[i] = signal1[i] + signal2[i];
    }

    std::vector<std::complex<double>> dftResult = dft(signal);

    writeDFTToFile(dftResult, "dftResults.csv");

    return 0;


}
