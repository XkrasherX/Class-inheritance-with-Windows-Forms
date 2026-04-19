#include "CManagerEmployee.h"
#include <iostream>
#include <iomanip>
using namespace std;

CManagerEmployee::CManagerEmployee()
	: CEmployee(), numOfWorkers(0)
{
	name = "Manager";
	hour_rate = 0.0;
}

CManagerEmployee::CManagerEmployee(string name, double hour_rate, int numOfWorkers)
	: CEmployee()
{
	this->name = name;
	this->hour_rate = hour_rate;
	this->numOfWorkers = numOfWorkers;
}
CManagerEmployee::~CManagerEmployee() {}

void CManagerEmployee::PrintName() const
{
	cout << "Manager: " << name << endl;
}

double CManagerEmployee::CalculateSalaryForHours(double dWorkedHours) const
{
	double baseSalary = dWorkedHours * 31.0;
	double bonusByWorker = numOfWorkers * 13.0;
	return baseSalary + bonusByWorker;
}

void CManagerEmployee::DisplayInfo() const
{
	cout << "Role: Manager" << endl;
	cout << "Name: " << name << endl;
	cout << "Hour Rate: $" << fixed << setprecision(2) << hour_rate << "/hour" << endl;
	cout << "Workers Managed: " << numOfWorkers << endl;
	cout << "Salary (40 hours): $" << fixed << setprecision(2) << CalculateSalaryForHours(40) << endl;
	cout << "Productivity Score: " << GetProductivityScore() << "/100" << endl;
	cout << endl;
}

int CManagerEmployee::GetProductivityScore() const
{
	int score = (numOfWorkers * 5);
	return (score > 100) ? 100 : score;
}