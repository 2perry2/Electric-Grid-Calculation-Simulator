#include "TEIRCustomer.h"


	//Constructors and destructors
TIERCustomer::TIERCustomer(Reading values[], int elecMeterID) {
		readings = values;
		meterID = elecMeterID;
		totalKWh();
		balance = computeBalance();
	}
	TIERCustomer::TIERCustomer() {}
	TIERCustomer::~TIERCustomer() {};

	//Accessor Method
	double TIERCustomer::getTotalKW() {
		return totalKW;
	}

	double TIERCustomer::getBalance() {
		return balance;
	}

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