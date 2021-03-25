#include "Reading.h"


#pragma once
#ifndef customer
#define customer
class Customer {

protected:
	Reading* readings;
	int meterID;
	double totalKW = 0, balance = 0;

public:
	Customer();

	~Customer();
	//Mutators 
	void addReading(int, float);
	void setBalance(double bal);

	//Methods
	void totalKWh();
	//Acessor Methods
	double getBalance();

	//Virtual Functions

	virtual double computeBalance() = 0;
};
#endif // !customer

