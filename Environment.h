#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class Environment {
private:
    double temperature;
    double humidity;

public:
    Environment(double initTemperature = 20.0, double initHumidity = 50.0);
    void simulateSensorReadings();
    void updateConditions(double deltaTemp, double deltaHumidity);
    void reportStatus() const;
};

#endif