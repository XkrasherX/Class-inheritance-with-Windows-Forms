#pragma once
#include "CEmployee.h"


class CManagerEmployee : public virtual CEmployee
{
protected:
	int numOfWorkers;

public:
	CManagerEmployee();
	CManagerEmployee(std::string name, double hour_rate, int numOfWorkers);
	~CManagerEmployee() override;

	void PrintName() const override;
	double CalculateSalaryForHours(double dWorkedHours) const override;
	void DisplayInfo() const override;
	
	int GetNumOfWorkers() const { return numOfWorkers; }
	void SetNumOfWorkers(int workers) { numOfWorkers = workers; }


	int GetProductivityScore() const;
};