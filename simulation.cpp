#include "simulation.h"


// TODO: 
// Purpose: When object is created all nessesary functions to populate the object are computed 
simulation::simulation() {
	createCustomers();
	Averages();
	minMax();
}

//TODO: Method Complete
//Purpose: This method creates the 1000 customers of each type and populates their readings and nessesary values aswell as a unique meter reading for all customers
void simulation::createCustomers() {

	for (int c = 0; c < 2; c++) {
		srand(time(NULL));
		for (int x = 0; x < customerNum; x++) {
			count = 0;
			for (int y = 0; y < 30; y++) {
				for (int z = 1; z <= 24; z++) {

					readerKW = (rand() % (200 - 5 + 1) + 5);
					readerKW = double(readerKW) / 100.00;
					values[count] = Reading(z, readerKW);
					count++;
				}
			}
			// Creation of customer objects and meter ID

			meterID = (rand() % (999999 - 100000 + 1) + 100000);
			if (c == 0) {
				touCustomers.push_back(TOUCustomer(values, meterID));
			}
			else if (c == 1) {
				TIERCustomers.push_back(TIERCustomer(values, meterID));
			}
		}
	}
}

//TODO: Method Complete
//Purpose: This method takes the balance and total kWh usage of each customer and calulates the average of both types of customers
void simulation::Averages() {
	for (int i = 0; i < 1000; i++) {
		avgConsumTOU += touCustomers[i].getTotalKW();
		avgConsumTIER += TIERCustomers[i].getTotalKW();
		avgBalTOU += touCustomers[i].getBalance();
		avgBalTIER += TIERCustomers[i].getBalance();
	}
	avgConsumTIER = avgConsumTIER / 1000;
	avgConsumTOU = avgConsumTOU / 1000;
	avgBalTOU = avgBalTOU / 1000;
	avgBalTIER = avgBalTIER / 1000;
}

// TODO: Method Complete:
// Purpose: This method takes the total kWh and balance of each customer and compares it to the current highest and lowest value of each measurement 
// It then replaces the values if the placeholder value is higher than the current hightest value or lower than the current lowest value
void simulation::minMax() {

	for (int i = 0; i < 1000; i++) {
		placeholdTOU = touCustomers[i].getBalance();
		placeholdTIER = TIERCustomers[i].getBalance();
		if (placeholdTIER < smallestBalTIER) {
			smallestBalTIER = placeholdTIER;
		}
		if (placeholdTIER >= largestBalTIER) {
			largestBalTIER = placeholdTIER;
		}
		if (placeholdTOU <= SmallestBalTOU) {
			SmallestBalTOU = placeholdTOU;
		}
		if (placeholdTOU >= largestBalTOU) {
			largestBalTOU = placeholdTOU;
		}
	}
}

// TODO: Method Complete 
// Purpose: this method gathers all the variables which values were computed at object creation and prints them out in a neatly formated way
void simulation::printResult() {

	std::cout << std::setw(30) << "Simulation Run:" << std::endl << std::endl;
	std::cout << std::setw(50) << "Number of customers in each group: \t" << customerNum << "\n \n \n" << std::endl;
	std::cout << std::setw(30) << "TOU Customer: \n\n";
	std::cout << std::setw(50) << "Average electric consumption: \t" << std::setprecision(2) << std::fixed << avgConsumTOU << " kWh\n";
	std::cout << std::setw(50) << "Average balance per customer: \t$" << std::setprecision(2) << std::fixed << avgBalTOU << "\n";
	std::cout << std::setw(50) << "Largest balance: \t$" << std::setprecision(2) << std::fixed << largestBalTOU << "\n";
	std::cout << std::setw(50) << "Smallest balance: \t$" << std::setprecision(2) << std::fixed << SmallestBalTOU << "\n\n";
	std::cout << std::setw(30) << "TIER Customer: \n\n";
	std::cout << std::setw(50) << "Average electric consumption: \t" << std::setprecision(2) << std::fixed << avgConsumTIER << " kWh\n";
	std::cout << std::setw(50) << "Average balance per customer: \t$" << std::setprecision(2) << std::fixed << avgBalTIER << "\n";
	std::cout << std::setw(50) << "Largest balance: \t$" << std::setprecision(2) << std::fixed << largestBalTIER << "\n";
	std::cout << std::setw(50) << "Smallest balance: \t$" << std::setprecision(2) << std::fixed << smallestBalTIER << "\n\n\n";
	system("pause");
}

