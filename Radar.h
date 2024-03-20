#ifndef RADAR_H
#define RADAR_H

#include<vector>

struct RadarEcho {
	double distance;
	double velocity;
};

class Radar {
public:
	Radar();
	~Radar();
	void emitAndReceivePulses();
	void processRadarData();
	void integrateWithSimulation();
	void displayRadarInfo();
private:
	std::vector<RadarEcho> echoes;
};

#endif