#include "MazeRunner.h"
#include "Coord.h"

#include <iostream>

int main(int argc, const char * argv[]) {
	auto startTime = std::clock();
	
	auto numSteps = countSteps({31, 39}, 1362);
	auto numVisited = fiftySteps(1362);
	
	double duration = ( std::clock() - startTime ) / static_cast<double>(CLOCKS_PER_SEC);

	std::cout << "Number of steps: " << numSteps << std::endl;
	std::cout << "Unique visits: " << numVisited << std::endl;
	std::cout << "Time: " << duration << std::endl;

	return EXIT_SUCCESS;
}
