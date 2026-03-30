#include "CSalemanEmployee.h"
#include <iostream>
using namespace std;
CSalesmanEmployee::CSalesmanEmployee()
{
	name = "Saleman";
	hour_rate = 0;
}

CSalesmanEmployee::CSalesmanEmployee(string m_name, double m_hour_rate, int sold_products)
{
	name = m_name;
	hour_rate = m_hour_rate;
	numOfSaledItem = sold_products;
}

void CSalesmanEmployee::PrintName() const
{
	cout << "Saleman!" << endl;
}

double CSalesmanEmployee::CalculateSalaryForHours(double dWorkedHours) const
{
	double baseSalary = dWorkedHours * 24.0;
	double bonusByWorker = numOfSaledItem * 8.0;
	return baseSalary + bonusByWorker;
}