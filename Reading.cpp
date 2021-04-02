#include "Reading.h"


// Purpose: Constructor if recieves no reading initalizes with values outside the bounds for later calculations
Reading::Reading() {
	// if no input is used the reading will default to -1 which in this case signifies no reading in that array slot
	meterRead = 0.0;
	hour = -1;
}

// Purpose: Constructor takes in the time and meter reading and stores them together for later reference in specific customer type pricing plans
Reading::Reading(int time, float kWh) {
	meterRead = kWh;
	hour = time;
}

// Default destructor
Reading::~Reading() {}

//Accessor methods
float Reading::getMeterRead() { return meterRead; }
int Reading::getHour() { return hour; }

//mutator methods
void Reading::setMeterRead(float kWh) {
	meterRead = kWh;
}
void Reading::setHour(int time) {
	hour = time;
}
