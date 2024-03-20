#include "Environment.h"
#include <random>

static std::mt19937 rng(std::random_device{}()); // Seed with a real random value, if available

Environment::Environment(double initTemperature, double initHumidity)
	: temperature(initTemperature), humidity(initHumidity) {
	// Initialization logic, if needed
}

void Environment::simulateSensorReadings() {
	// Simulate sensor reading by introducing random variations

	// Explanation: 
	//   rand() returns an int type
	//   static_cast<double> converts the int type to the double type
	//   RAND_MAX is a constant defined in the C standard library
	temperature += static_cast<double>(rand()) / RAND_MAX - 0.5;
	humidity += static_cast<double>(rand()) / RAND_MAX - 1.0;

}

void Environment::updateConditions(double deltaTemp, double deltaHumidity) {
	temperature += deltaTemp;
	humidity += deltaHumidity;

}

void Environment::reportStatus() const {
	// Prints temperature and humidity to the console
	// 
	// Learning note: The `const` keyword
	//  The const keyword indicates intention to not change any Environment member variables
	std::cout << std::fixed << std::setprecision(2) 
		<< "Temperature: " << temperature << "°C, Humidity: " << humidity << "%" 
		<< std::endl;

}