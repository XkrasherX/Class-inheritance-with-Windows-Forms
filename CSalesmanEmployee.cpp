#include "CSalesmanEmployee.h"
#include <iostream>
#include <iomanip>
using namespace std;

CSalesmanEmployee::CSalesmanEmployee()
	: CEmployee(), numOfSaledItem(0)
{
	name = "Salesman";
	hour_rate = 0.0;
}

CSalesmanEmployee::CSalesmanEmployee(string name, double hour_rate, int sold_products)
	: CEmployee()
{
	this->name = name;
	this->hour_rate = hour_rate;
	this->numOfSaledItem = sold_products;
}

CSalesmanEmployee::~CSalesmanEmployee() {}

void CSalesmanEmployee::PrintName() const
{
	cout << "Salesman: " << name << endl;
}

double CSalesmanEmployee::CalculateSalaryForHours(double dWorkedHours) const
{
	double baseSalary = dWorkedHours * 25.0;
	double commission = numOfSaledItem * 50.0;
	return baseSalary + commission;
}

void CSalesmanEmployee::DisplayInfo() const
{
	cout << "Role: Salesman" << endl;
	cout << "Name: " << name << endl;
	cout << "Hour Rate: $" << fixed << setprecision(2) << hour_rate << "/hour" << endl;
	cout << "Products Sold: " << numOfSaledItem << endl;
	cout << "Salary (40 hours): $" << fixed << setprecision(2) << CalculateSalaryForHours(40) << endl;
	cout << "Productivity Score: " << GetProductivityScore() << "/100" << endl;
	cout << endl;
}

int CSalesmanEmployee::GetProductivityScore() const
{
	int score = (numOfSaledItem * 3);
	return (score > 100) ? 100 : score;
}