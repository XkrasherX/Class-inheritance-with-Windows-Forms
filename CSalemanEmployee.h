#pragma once
#include "CEmployee.h"

class CSalesmanEmployee : protected CEmployee {
protected:
	int numOfSaledItem;
public:
	CSalesmanEmployee();
	CSalesmanEmployee(std::string m_name, double m_hour_rate, int sold_products);
	void PrintName() const;
	double CalculateSalaryForHours(double dWorkedHours) const;
};