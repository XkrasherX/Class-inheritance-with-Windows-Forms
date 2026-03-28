#pragma once
#include <string>


class CEmployee {
protected:
	string name;
	double hour_rate;
public:
	CEmployee();
	CEmployee(string m_name, double m_hour_rate);
	void PrintName() const;
	double CalculateSalaryForHours( double dWorkedHours) const;
};


