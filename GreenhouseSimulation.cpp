// GreenhouseSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Environment.h"
#include "Radar.h"

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
