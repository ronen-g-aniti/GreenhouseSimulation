#include "Radar.h"


/*
* Radar works be emitting EM waves (typically radio).
* The EM waves hit targets.
* The EM waves bounce back.
* The bounced-back waves are called echoes.
* Radar provides a depiction of the motion and existence of targets
*  from the surrounding area, in this case, precipitation, terrain,
*  airborne objects.
* Radar & Weather: Radar echoes can clue us in to changes
*  in weather phenomena since certain weather patterns
*  are known to produce distinct radar signatures.
*
*/

Radar::Radar() {
}

Radar::~Radar() {
	/*
	* Learning note: Destructors in C++
	* Destructors "clean up" resources
	* For example, any radar echoes that are stored with
	*  a Radar instance would be destroyed, freeing up
	*  system resources
	*/
}

// Method to emit radar pulses and receive echoes
void Radar::emitAndReceivePulses() {
	// Simulate emitting radar pulses and receiving echoes
	// Update the echoes vector with received data
}

// Method to process radar data
void Radar::processRadarData() {
	// Implement signal processing algorithms to analyze radar data
	// Extract information such as distance, velocity, and properties of targets
}

// Method to integrate radar data with greenhouse simulation
void Radar::integrateWithSimulation() {
	// Integrate radar data with other components of the simulation
	// Update the state of the greenhouse based on radar observations
}

// Method to display radar information
void Radar::displayRadarInfo() {
	// Display radar data or visualization of radar observations
}

// Add more methods as needed to configure radar parameters, access data, etc.
