#pragma once
#include <string>

class CEmployee
{
protected:
	std::string name;
	double hour_rate;

public:
	virtual ~CEmployee() = 0;

	virtual void PrintName() const = 0;

	virtual double CalculateSalaryForHours(double dWorkedHours) const = 0;

	virtual std::string GetName() const { return name; }

	virtual double GetHourRate() const { return hour_rate; }

	virtual void DisplayInfo() const = 0;
};