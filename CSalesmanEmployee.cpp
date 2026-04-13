#include "CSalesmanEmployee.h"
#include <iostream>
using namespace std;

CSalesmanEmployee::CSalesmanEmployee()
{
	name = "Salesman";
	hour_rate = 0;
	numOfSaledItem = 0;
}

CSalesmanEmployee::CSalesmanEmployee(string m_name, double m_hour_rate, int sold_products)
{
	name = m_name;
	hour_rate = m_hour_rate;
	numOfSaledItem = sold_products;
}

void CSalesmanEmployee::PrintName() const
{
	cout << "Salesman!" << endl;
}

double CSalesmanEmployee::CalculateSalaryForHours(double dWorkedHours) const
{
	double baseSalary = dWorkedHours * 25.0;
	double commissionPerItem = numOfSaledItem * 10.0;
	return baseSalary + commissionPerItem;
}

void CSalesmanEmployee::DisplayProductivity() const
{
	cout << "Salesman Productivity Report:" << endl;
	cout << "Name: " << name << endl;
	cout << "Products Sold: " << numOfSaledItem << endl;
	cout << "Productivity Score: " << GetProductivityScore() << "/100" << endl;
}

int CSalesmanEmployee::GetProductivityScore() const
{
	
	int score = (numOfSaledItem * 3);
	return (score > 100) ? 100 : score;
}