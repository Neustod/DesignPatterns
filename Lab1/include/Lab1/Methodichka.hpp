#pragma once


class Methodichka 
{
protected:
	Methodichka() {};

	Methodichka(const Methodichka& src) {};

protected:
	virtual void DesignStage() = 0;

	virtual void CalculationStage() = 0;

	virtual void ReleaseStage() = 0;

public:
	void DoWork();
};