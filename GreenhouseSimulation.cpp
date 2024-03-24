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

    double fc = 1000.0; // Carrier frequency in Hz
    double pw = 0.01; // Pulse width in seconds
    double pri = 0.1; // Pulse repetition interval in seconds
    double amplitude = 1.0; // Amplitude of the signal
    int n_pulses = 10; // Number of pulses
    double fs = 5000.0; // Sampling rate in Hz

    std::vector<double> radarSignal = generateRadarSignal(fc, pw, pri, amplitude, n_pulses, fs);
    
    // Write radar signal to CSV
    writeTimeDomainSignalToCSV(radarSignal, "timeDomainSignal.csv", fs);

    // Now you can analyze the radar signal using the DFT to understand its frequency components
    std::vector<std::complex<double>> dftResult = dft(radarSignal);
    writeDFTToFile(dftResult, "dftResults.csv");

    return 0;


}
