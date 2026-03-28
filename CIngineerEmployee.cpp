#include "CIngineerEmployee.h"
#include <iostream>
using namespace std;

CEngineerEmployee::CEngineerEmployee()
{
	name = "Engineer";
	hour_rate = 0;
}

CEngineerEmployee::CEngineerEmployee(string m_name, double m_hour_rate, int fixed_details)
{
	name = m_name;
	hour_rate = m_hour_rate;
	numOfFixedDetails = fixed_details;
}

void CEngineerEmployee::PrintName() const
{
	cout << "Engineer!" << endl;
}

double CEngineerEmployee::CalculateSalaryForHours(double dWorkedHours) const
{
	double baseSalary = dWorkedHours * hour_rate;
	double bonusByWorker = numOfFixedDetails * 15.0;
	return baseSalary + bonusByWorker;
}

