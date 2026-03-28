#include "CEmployee.h"
using namespace std;

void CEmployee::PrintName() { cout << "Employee!" << endl; }

double CEmployee::calulateSalryForHimself(int numOfItems) {	return 0.0; }

double CEmployee::CalculateSalaryForHours(const double dWorkedHours) { return 0.0; }

void CManagerEmployee::CEmployee::PrintName() { cout << "Manager" << endl; }

void CSalesmanEmployee::CEmployee::PrintName() { cout << "Salesman" << endl; }

void CEngineerEmployee::CEmployee::PrintName() { cout << "Engineer" << endl; }

