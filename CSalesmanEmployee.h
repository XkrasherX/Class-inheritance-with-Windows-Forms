#pragma once
#include "CEmployee.h"
#include "IProductivityTracker.h"

class CSalesmanEmployee : public virtual CEmployee, public virtual IProductivityTracker {
protected:
	int numOfSaledItem;
public:
	CSalesmanEmployee();
	CSalesmanEmployee(std::string m_name, double m_hour_rate, int sold_products);
	void PrintName() const override;
	double CalculateSalaryForHours(double dWorkedHours) const override;
	void DisplayProductivity() const override;
	int GetProductivityScore() const override;
};