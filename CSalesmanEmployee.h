#pragma once
#include "CEmployee.h"

class CSalesmanEmployee : public virtual CEmployee
{
protected:
	int numOfSaledItem;

public:
	CSalesmanEmployee();
	CSalesmanEmployee(std::string name, double hour_rate, int sold_products);
	~CSalesmanEmployee() override;

	void PrintName() const override;
	double CalculateSalaryForHours(double dWorkedHours) const override;
	void DisplayInfo() const override;
	
	int GetNumOfSaledItem() const { return numOfSaledItem; }
	void SetNumOfSaledItem(int items) { numOfSaledItem = items; }

	int GetProductivityScore() const;
};