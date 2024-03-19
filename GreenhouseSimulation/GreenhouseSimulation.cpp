// GreenhouseSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class Environment {
private:
	double temperature;
	double humidity;

public:
	Environment(double initTemperature = 20.0, double initHumidity = 50.0)
		: temperature(initTemperature), humidity(initHumidity) {
		std::srand(std::time(nullptr)); // Seed the random number generator
	}

	void simulateSensorReadings() {
		// Simulate sensor reading by introducing random variations
		
		// Explanation: 
		//   rand() returns an int type
		//   static_cast<double> converts the int type to the double type
		//   RAND_MAX is a constant defined in the C standard library
		temperature += static_cast<double>(rand()) / RAND_MAX - 0.5;
		humidity += static_cast<double>(rand()) / RAND_MAX - 1.0;

	}

	void updateConditions(double deltaTemp, double deltaHumidity){
		temperature += deltaTemp;
		humidity += deltaHumidity;

	}

	void reportStatus() const {
	
		std::cout << std::fixed << std::setprecision(2) << "Temperature: " << temperature << "°C, Humidity: " << humidity << "%" << std::endl;

	}

};



int main()
{
	Environment env;
	env.reportStatus();
	env.simulateSensorReadings();
	env.reportStatus();
	env.updateConditions(2.0, -5.0);
	env.reportStatus();

	return 0;
}
