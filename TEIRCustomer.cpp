#include "TEIRCustomer.h"

// TODO: Method Complete 
// Purpose: Constructor that initalizes the object parameters and calculates the balance of the customer
TIERCustomer::TIERCustomer(Reading values[], int elecMeterID) {
		readings = values;
		meterID = elecMeterID;
		totalKWh();
		balance = computeBalance();
	}
	TIERCustomer::TIERCustomer() {}
	TIERCustomer::~TIERCustomer() {};


// Accessor Methods
double TIERCustomer::getTotalKW() {
	return totalKW;
}

double TIERCustomer::getBalance() {
	return balance;
}

// Purpose: Computes the balance of the customer using the Teir based pricing plan
// TODO: Method Complete
double TIERCustomer::computeBalance(){
	// Note: all times are from 1 to 24 with 1 being a reading taken from 12:01 to 12:59 and 24 being a reading taken from 11:01pm to 11:59pm
	for (int x = 0; x < 720; x++) {
		if (totalKW <= 1000) {
			balance += readings[x].getMeterRead() * 0.126;
		}
		else {
			balance += readings[x].getMeterRead() * 0.146;
		}
	}
	return balance;
}