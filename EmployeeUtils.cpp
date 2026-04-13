#include "EmployeeUtils.h"
#include "CManagerEmployee.h"
#include "CSalesmanEmployee.h"
#include "CEngineerEmployee.h"
#include <iostream>
using namespace std;

double CalculateTotalSalary(CEmployee** employees, int count, double workedHours)
{
	double totalSalary = 0.0;
	for (int i = 0; i < count; i++)
	{
		if (employees[i] != nullptr)
		{
			totalSalary += employees[i]->CalculateSalaryForHours(workedHours);

			CManagerEmployee* manager = dynamic_cast<CManagerEmployee*>(employees[i]);
			if (manager != nullptr)
			{
				cout << "Employee " << i + 1 << " is a Manager" << endl;
			}

			CSalesmanEmployee* salesman = dynamic_cast<CSalesmanEmployee*>(employees[i]);
			if (salesman != nullptr)
			{
				cout << "Employee " << i + 1 << " is a Salesman" << endl;
			}

			CEngineerEmployee* engineer = dynamic_cast<CEngineerEmployee*>(employees[i]);
			if (engineer != nullptr)
			{
				cout << "Employee " << i + 1 << " is an Engineer" << endl;
			}
		}
	}
	return totalSalary;
}

void PrintEmployeeInfo(CEmployee* employee)
{
	if (employee != nullptr)
	{
		employee->PrintName();
	}
}