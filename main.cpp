#include "simulation.h"

// TODO: Main Method Complete
// Purpose: Run the simulation of all classes created and output the results of the simulation calculation
int main() {
	simulation* sim = new simulation();
	sim->printResult();

	delete sim;
	return 0;
}