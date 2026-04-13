#include "CEngineerEmployee.h"
#include <iostream>
using namespace std;

CEngineerEmployee::CEngineerEmployee()
{
	name = "Engineer";
	hour_rate = 0;
	numOfFixedDetails = 0;
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
	double baseSalary = dWorkedHours * 20.0;
	double bonusPerDetail = numOfFixedDetails * 50.0;
	return baseSalary + bonusPerDetail;
}

void CEngineerEmployee::DisplayProductivity() const
{
	cout << "Engineer Productivity Report:" << endl;
	cout << "Name: " << name << endl;
	cout << "Details Created: " << numOfFixedDetails << endl;
	cout << "Productivity Score: " << GetProductivityScore() << "/100" << endl;
}

int CEngineerEmployee::GetProductivityScore() const
{
	
	int score = (numOfFixedDetails * 4);
	return (score > 100) ? 100 : score;
}