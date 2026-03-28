#pragma once
#include <iostream>


class CEmployee {
protected:
	string name;
	double hour_rate;
public:
	void PrintName();
	double calulateSalryForHimself(int numOfItems);
	double CalculateSalaryForHours(const double dWorkedHours);
};


