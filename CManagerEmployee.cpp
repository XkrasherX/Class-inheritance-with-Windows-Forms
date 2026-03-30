#include "CManagerEmployee.h"
#include <iostream>
using namespace std;

CManagerEmployee::CManagerEmployee()
{
	name = "Manager";
	hour_rate = 0;
	numOfWorkers = 0;
}

CManagerEmployee::CManagerEmployee(string m_name, double m_hour_rate, int m_numOfWorkers)
{
	name = m_name;
	hour_rate = m_hour_rate;
	numOfWorkers = m_numOfWorkers;
}

void CManagerEmployee::PrintName() const
{
	cout << "Manager!" << endl;
}

double CManagerEmployee::CalculateSalaryForHours(double dWorkedHours) const
{
	double baseSalary = dWorkedHours * 31.0;
	double bonusByWorker = numOfWorkers * 13.0;
	return baseSalary + bonusByWorker;
}


