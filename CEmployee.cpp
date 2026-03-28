#include "CEmployee.h"


void CEmployee::PrintName() { cout << "This is CEmployee class!" << endl; }

double CEmployee::calulateSalryForHimself(int numOfItems) {	return 0.0; }

double CalculateSalaryForHours(const double dWorkedHours) { return dWorkedHours * 8.0; }

void CManagerEmployee::CEmployee::PrintName() { cout << "This is CManagerEmployee class!" << endl; }

void CSalesmanEmployee::CEmployee::PrintName() { cout << "This is CSalesmanEmployee class!" << endl; }

void CEngineerEmployee::CEmployee::PrintName() { cout << "This is CEngineerEmployee class!" << endl; }

