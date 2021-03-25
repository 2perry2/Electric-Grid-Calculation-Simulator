#include "TEIRCustomer.h"
#include "TOUCustomer.h"
#include <vector>
#include <ctime>
#include <iostream>
#include <iomanip>

#pragma once

#ifndef Sim
#define Sim
class simulation {
private:
	//Constants
	const int customerNum = 1000;
	//Results variables
	double avgConsumTOU, avgConsumTIER, avgBalTOU, avgBalTIER, largestBalTOU = 0, largestBalTIER = 0, SmallestBalTOU = 10000000, smallestBalTIER = 10000000;

	//Variables used for random generation
	double readerKW, totalKW, placeholdTOU, placeholdTIER;
	int count = 0, meterID;
	Reading values[720];

	std::vector<TOUCustomer> touCustomers;
	std::vector<TIERCustomer> TIERCustomers;

public:

	//When object is created all nessesary functions to populate the object are computed 
	simulation();

	//This method creates the 1000 customers of each type and populates their readings and nessesary values aswell as a unique meter reading for all customers
	void createCustomers();

	//This method takes the balance and total kWh usage of each customer and calulates the average of both types of customers
	void Averages();

	// This method takes the total kWh and balance of each customer and compares it to the current highest and lowest value of each measurement 
	// It then replaces the values if the placeholder value is higher than the current hightest value or lower than the current lowest value
	void minMax();

	// The output method: this method gathers all the variables which values were computed at object creation and prints them out in a neat formated maner
	void printResult();

};

#endif // !Sim
