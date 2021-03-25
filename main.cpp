#include "simulation.h"


int main() {
	simulation* sim = new simulation();
	sim->printResult();

	delete sim;
	return 0;
}