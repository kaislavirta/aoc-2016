#include "MazeRunner.h"

#include <iostream>

int main(int argc, const char * argv[]) {
	MazeRunner mr1(1362);
	auto numSteps = mr1.countSteps(31, 39);
	std::cout << "Number of steps: " << numSteps << std::endl;

	MazeRunner mr2(1362);
	auto numVisited = mr2.fiftySteps();
	std::cout << "Unique visits: " << numVisited << std::endl;

	return EXIT_SUCCESS;
}
