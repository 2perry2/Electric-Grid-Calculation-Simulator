#include "Customer.h"

// Purpose: Constructor initalizes all values with defaults allowing for calculations in classes which inherit this class to modify them safely
Customer::Customer() {
	balance = 0.0;
	meterID = 0;
	totalKW = 0.0;
	readings = new Reading();

}

//Default Destructor
Customer::~Customer() {}


// TODO: Method complete
// Purpose: Method takes the time input and the meter reading in kWh and stores it in the members 
void Customer::addReading(int time, float kWh) {
	for (int x = 0; x < sizeof(readings); x++) {
		if (readings[x].getHour() == -1) {
			readings[x].setHour(time);
			readings[x].setMeterRead(kWh);
		}
	}
}

// Purpose: Gets the total readings for each customer and gets the total
// TODO: Method Complete
void Customer::totalKWh() {
	for (int x = 0; x < 720; x++) {
		totalKW += readings[x].getMeterRead();
	}
}

// Mutator Methods
void Customer::setBalance(double bal) {
	balance = bal;
}

//Acessor Methods
double Customer::getBalance() {
	return balance;
}
