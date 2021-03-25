#include "TOUCustomer.h"



//Default Constructor
TOUCustomer::TOUCustomer() {}

TOUCustomer::TOUCustomer(Reading values[], int elecMeterID) {
	readings = values;
	meterID = elecMeterID;
	totalKWh();
	balance = computeBalance();
}

//Destructor
TOUCustomer::~TOUCustomer() {};

double TOUCustomer::computeBalance()  {
	// Note: all times are from 1 to 24 with 1 being a reading taken from 12:01 to 12:59 and 24 being a reading taken from 11:01pm to 11:59pm
	for (int x = 0; x < 720; x++) {
		if ((8 >= readings[x].getHour() && readings[x].getHour() < 12) && (18 >= readings[x].getHour() && readings[x].getHour() < 20)) {
			balance += readings[x].getMeterRead() * 0.217;
		}
		else if (12 >= readings[x].getHour() && readings[x].getHour() < 18) {
			balance += readings[x].getMeterRead() * 0.150;
		}
		else if ((20 >= readings[x].getHour() && readings[x].getHour() < 24) && (1 >= readings[x].getHour() && readings[x].getHour() < 8)) {
			balance += readings[x].getMeterRead() * 0.105;
		}

	}
	return balance;
}

//Accessor Methods
double TOUCustomer::getTotalKW() {
	return totalKW;
}

double TOUCustomer::getBalance() {
	return balance;
}