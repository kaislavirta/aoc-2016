#include "MazeRunner.h"
#include "Coord.h"

#include <iostream>

int main(int argc, const char * argv[]) {
	auto numSteps = countSteps({31, 39}, 1362);
	std::cout << "Number of steps: " << numSteps << std::endl;

	auto numVisited = fiftySteps(1362);
	std::cout << "Unique visits: " << numVisited << std::endl;

	return EXIT_SUCCESS;
}
