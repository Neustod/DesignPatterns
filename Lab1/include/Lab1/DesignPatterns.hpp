#pragma once
#include "Lab1/Methodichka.hpp"
#include <string>


class DesignPatterns : public Methodichka
{
public:
	DesignPatterns() {};

private:
	void DesignStage() override;

	void CalculationStage() override;

	void ReleaseStage() override;
};