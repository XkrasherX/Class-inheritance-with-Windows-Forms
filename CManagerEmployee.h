#pragma once
#include "CEmployee.h"
#include "IProductivityTracker.h"

class CManagerEmployee : public virtual CEmployee, public virtual IProductivityTracker {
protected:
	int numOfWorkers;
public:
	CManagerEmployee();
	CManagerEmployee(std::string name, double hour_rate, int numOfWorkers);
	void PrintName() const override;
	double CalculateSalaryForHours(double dWorkedHours) const override;
	void DisplayProductivity() const override;
	int GetProductivityScore() const override;
};