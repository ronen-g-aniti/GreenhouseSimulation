#include "fourierTransform.h"


std::vector<double> generateSineWave(double frequency, double amplitude, int numSamples, double fs) {
    std::vector<double> signal(numSamples);
    for (int i = 0; i < numSamples; ++i) {
        double time = i / fs;
        signal[i] = amplitude * sin(2 * M_PI * frequency * time);
    }
    return signal;
}

std::vector<std::complex<double>> dft(const std::vector<double>& signal) {
    int N = signal.size();
    std::vector<std::complex<double>> result(N);

    for (int k = 0; k < N; ++k) {
        std::complex<double> sum(0.0, 0.0);
        for (int n = 0; n < N; ++n) {
            double angle = -2.0 * M_PI * k * n / N;
            std::complex<double> exp_term(std::cos(angle), std::sin(angle));
            sum += signal[n] * exp_term;
        }
        result[k] = sum / static_cast<double>(N); // Apply normalization
    }
    return result;
}


void writeDFTToFile(const std::vector<std::complex<double>>& dftResult, const std::string& filename) {
	std::ofstream file(filename);
	for (const auto& value : dftResult) {
		file << value.real() << "," << value.imag() << std::endl;
	}
	file.close();
}

void writeTimeDomainSignalToCSV(const std::vector<double>& signal, const std::string& filename, double fs) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Time,Amplitude\n"; // Write the header row
        for (size_t i = 0; i < signal.size(); ++i) {
            double time = i / fs; // Calculate the time for each sample
            file << time << "," << signal[i] << "\n"; // Write time and amplitude separated by a comma
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

std::vector<double> generateRadarSignal(double fc, double pw, double pri, double amplitude, int n_pulses, double fs) {
    int samplesPerPulse = static_cast<int>(pw * fs);
    int samplesPerPRI = static_cast<int>(pri * fs);
    int totalSamples = n_pulses * samplesPerPRI;
    std::vector<double> radarSignal(totalSamples, 0.0);

    for (int p = 0; p < n_pulses; ++p) {
        std::vector<double> pulse = generateSineWave(fc, amplitude, samplesPerPulse, fs);
        for (int i = 0; i < samplesPerPulse; ++i) {
            radarSignal[p * samplesPerPRI + i] = pulse[i];
        }
    }

    return radarSignal;
}


