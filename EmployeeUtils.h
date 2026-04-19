#pragma once
#include "CEmployee.h"

double CalculateTotalSalary(CEmployee** employees, int count, double workedHours);

void PrintEmployeeInfo(CEmployee* employee);

void DisplayAllEmployeesInfo(CEmployee** employees, int count);

void CountEmployeesByType(CEmployee** employees, int count);