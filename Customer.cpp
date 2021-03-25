#include "Customer.h"


Customer::Customer() {
	balance = 0.0;
	meterID = 0;
	totalKW = 0.0;
	readings = new Reading();

}

Customer::~Customer() {}
//Mutators 
void Customer::addReading(int time, float kWh) {
	for (int x = 0; x < sizeof(readings); x++) {
		if (readings[x].getHour() == -1) {
			readings[x].setHour(time);
			readings[x].setMeterRead(kWh);
		}
	}
}
void Customer::setBalance(double bal) {
	balance = bal;
}

//Methods
void Customer::totalKWh() {
	for (int x = 0; x < 720; x++) {
		totalKW += readings[x].getMeterRead();
	}
}
//Acessor Methods
double Customer::getBalance() {
	return balance;
}
