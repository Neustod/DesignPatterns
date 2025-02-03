#include "Lab1/DesignPatterns.hpp"
#include <iostream>


void DesignPatterns::DesignStage()
{
	std::cout << "Making laboratory work...\nSubject: Design patterns" << std::endl;
	std::cout << "\n[Design stage]\n\tCreating UML-diagram...";

	// Some diagram creation routine...
	_sleep(500);

	std::cout << "[DONE]" << std::endl;
}

void DesignPatterns::CalculationStage()
{
	std::cout << "\n[Calculation stage]\n\tCalculating amount of dependences...";

	// Some calculation routine...
	_sleep(100);

	std::cout << "[DONE]" << std::endl;
}

void DesignPatterns::ReleaseStage()
{
	std::cout << "\n[Release stage]\n\tWriting C++ code...";

	// Some calculation routine...
	_sleep(800);

	std::cout << "[DONE]" << std::endl;
}
