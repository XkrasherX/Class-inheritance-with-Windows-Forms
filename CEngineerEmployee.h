#pragma once
#include "CEmployee.h"

class CEngineerEmployee : public CEmployee {
protected:
	int numOfFixedDetails;
public:
	CEngineerEmployee();
	CEngineerEmployee(std::string m_name, double m_hour_rate, int fixed_details);

	void PrintName() const;
	double CalculateSalaryForHours(double dWorkedHours) const;
};