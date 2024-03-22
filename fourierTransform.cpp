#include "fourierTransform.h"


std::vector<double> generateSineWave(double frequency, double amplitude, int numSamples) {
	std::vector<double> signal(numSamples);
	for (int i = 0; i < numSamples; ++i) {
		double time = i / static_cast<double>(numSamples);
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





