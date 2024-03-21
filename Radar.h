#ifndef RADAR_H
#define RADAR_H

#include <vector>

// Define a more comprehensive RadarEcho structure to include additional data
struct RadarEcho {
    float x; // X position of the echo
    float y; // Y position of the echo
    float z; // Z position of the echo
    float reflectivity; // Reflectivity value of the echo
};

class Radar {
public:
    // Constructor with resolution parameter
    Radar(float resolution);

    // Destructor
    ~Radar();

    // Setup the scanning area dimensions
    void setupScanningArea(float width, float length, float height);

    // Method to emit radar pulses and receive echoes
    void emitAndReceivePulses();

    // Process the collected radar data
    void processRadarData();

    // Integrate radar data with other components of the simulation
    void integrateWithSimulation();

    // Display or visualize the radar data
    void displayRadarInfo();

    // Method to dynamically set radar resolution
    void setResolution(float resolution);

private:
    std::vector<RadarEcho> echoes; // Vector to store received radar echoes
    float resolution_; // Radar resolution
    float scanningAreaWidth_; // Width of the scanning area
    float scanningAreaLength_; // Length of the scanning area
    float scanningAreaHeight_; // Height of the scanning area
};

#endif // RADAR_H
