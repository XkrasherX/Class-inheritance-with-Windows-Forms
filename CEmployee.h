#pragma once
#include <string>

class CEmployee {
protected:
	std::string name;
	double hour_rate;
public:
	CEmployee();
	CEmployee(std::string m_name, double m_hour_rate);
	virtual ~CEmployee();
	virtual void PrintName() const = 0;
	virtual double CalculateSalaryForHours(double dWorkedHours) const = 0;
};