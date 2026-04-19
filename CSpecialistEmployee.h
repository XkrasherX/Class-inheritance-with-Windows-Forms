#pragma once
#include "CManagerEmployee.h"
#include "CSalesmanEmployee.h"

class CSpecialistEmployee : public CManagerEmployee, public CSalesmanEmployee
{
private:
	double specialistBonus;

public:
	CSpecialistEmployee();
	CSpecialistEmployee(std::string name, double hour_rate, 
		int numOfWorkers, int numOfSoldItems, double bonus);
	~CSpecialistEmployee() override;

	void PrintName() const override;
	double CalculateSalaryForHours(double dWorkedHours) const override;
	void DisplayInfo() const override;

	double GetManagerSalary(double hours) const;
	double GetSalesmanSalary(double hours) const;

	double GetSpecialistBonus() const { return specialistBonus; }
	void SetSpecialistBonus(double bonus) { specialistBonus = bonus; }

	void DisplayCompleteInfo() const;
};