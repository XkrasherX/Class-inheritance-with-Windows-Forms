#include "CEmployee.h"
using namespace std;

CEmployee::CEmployee() : name("Worker"), hour_rate(4) {}

CEmployee::CEmployee(string m_name, double m_hour_rate) : name(m_name), hour_rate(m_hour_rate) {}

void CEmployee::PrintName() const { cout << "Employee!" << endl; }

double CEmployee::CalculateSalaryForHours(double dWorkedHours) const { return dWorkedHours * hour_rate; }