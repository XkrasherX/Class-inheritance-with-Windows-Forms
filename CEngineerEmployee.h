#pragma once
#include "CEmployee.h"

class CEngineerEmployee : public virtual CEmployee
{
protected:
	int numOfFixedDetails;

public:
	CEngineerEmployee();
	CEngineerEmployee(std::string name, double hour_rate, int fixed_details);
	~CEngineerEmployee() override;

	void PrintName() const override;
	double CalculateSalaryForHours(double dWorkedHours) const override;
	void DisplayInfo() const override;
	
	int GetNumOfFixedDetails() const { return numOfFixedDetails; }
	void SetNumOfFixedDetails(int details) { numOfFixedDetails = details; }

	int GetProductivityScore() const;
};