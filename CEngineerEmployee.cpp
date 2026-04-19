#include "CEngineerEmployee.h"
#include <iostream>
#include <iomanip>
using namespace std;

CEngineerEmployee::CEngineerEmployee()
	: CEmployee(), numOfFixedDetails(0)
{
	name = "Engineer";
	hour_rate = 0.0;
}

CEngineerEmployee::CEngineerEmployee(string name, double hour_rate, int fixed_details)
	: CEmployee()
{
	this->name = name;
	this->hour_rate = hour_rate;
	this->numOfFixedDetails = fixed_details;
}

CEngineerEmployee::~CEngineerEmployee() {}

void CEngineerEmployee::PrintName() const
{
	cout << "Engineer" << name << endl;
}

double CEngineerEmployee::CalculateSalaryForHours(double dWorkedHours) const
{
	double baseSalary = dWorkedHours * 35.0;
	double detailBonus = numOfFixedDetails * 20.0;
	return baseSalary + detailBonus;
}

void CEngineerEmployee::DisplayInfo() const
{
	cout << "Role: Engineer" << endl;
	cout << "Name: " << name << endl;
	cout << "Hour Rate: $" << fixed << setprecision(2) << hour_rate << "/hour" << endl;
	cout << "Fixed Details: " << numOfFixedDetails << endl;
	cout << "Salary (40 hours): $" << fixed << setprecision(2) << CalculateSalaryForHours(40) << endl;
	cout << "Productivity Score: " << GetProductivityScore() << "/100" << endl;
	cout << endl;
}

int CEngineerEmployee::GetProductivityScore() const
{
	int score = (numOfFixedDetails * 4);
	return (score > 100) ? 100 : score;
}