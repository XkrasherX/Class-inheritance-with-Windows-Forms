#pragma once
#include "CEmployee.h"
#include <string>

class CManagerEmployee : public CEmployee {
protected:
	int numOfWorkers;
public:
	CManagerEmployee();
	CManagerEmployee(string name, double hour_rate, int numOfWorkers);
	void PrintName() const;
	double CalculateSalaryForHours(double dWorkedHours) const;
};

