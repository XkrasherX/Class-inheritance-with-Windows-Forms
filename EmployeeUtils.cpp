#include "EmployeeUtils.h"
#include "CManagerEmployee.h"
#include "CSalesmanEmployee.h"
#include "CEngineerEmployee.h"
#include "CSpecialistEmployee.h"
#include <iostream>
#include <iomanip>
using namespace std;

double CalculateTotalSalary(CEmployee** employees, int count, double workedHours)
{
	if (!employees || count <= 0) return 0.0;

	double totalSalary = 0.0;
	cout << "\nTotal salary" << endl;
	cout << "Worked Hours: \n" << workedHours << endl;

	for (int i = 0; i < count; i++)
	{
		if (employees[i] != nullptr)
		{
			double salary = employees[i]->CalculateSalaryForHours(workedHours);
			totalSalary += salary;

			cout << "Employee #" << (i + 1) << ": ";
			employees[i]->PrintName();
			cout << "  Salary: $" << fixed << setprecision(2) << salary << endl;
		}
	}


	cout << "\nTotal salary for all employees: $" << fixed << setprecision(2) << totalSalary << endl;
	cout << endl;

	return totalSalary;
}

void PrintEmployeeInfo(CEmployee* employee)
{
	if (employee == nullptr)
	{
		cout << "Error: Employee pointer is null!" << endl;
		return;
	}

	employee->PrintName();
	employee->DisplayInfo();
}

void DisplayAllEmployeesInfo(CEmployee** employees, int count)
{
	if (!employees || count <= 0)
	{
		cout << "No employees to display." << endl;
		return;
	}

	cout << "\nInformation about all employees\n" << endl;


	for (int i = 0; i < count; i++)
	{
		if (employees[i] != nullptr)
		{
			cout << "\n[Employee #" << (i + 1) << "]" << endl;

			CSpecialistEmployee* specialist = dynamic_cast<CSpecialistEmployee*>(employees[i]);
			if (specialist != nullptr)
			{
				cout << "Specialist" << endl;
				specialist->DisplayCompleteInfo();
				continue;
			}

			CManagerEmployee* manager = dynamic_cast<CManagerEmployee*>(employees[i]);
			if (manager != nullptr)
			{
				cout << "Manager" << endl;
				manager->DisplayInfo();
				continue;
			}

			CSalesmanEmployee* salesman = dynamic_cast<CSalesmanEmployee*>(employees[i]);
			if (salesman != nullptr)
			{
				cout << "Salesman" << endl;
				salesman->DisplayInfo();
				continue;
			}

			CEngineerEmployee* engineer = dynamic_cast<CEngineerEmployee*>(employees[i]);
			if (engineer != nullptr)
			{
				cout << "Engineer" << endl;
				engineer->DisplayInfo();
				continue;
			}
		}
	}

	cout << endl << endl;
}

void CountEmployeesByType(CEmployee** employees, int count)
{
	if (!employees || count <= 0)
	{
		cout << "No employees to count." << endl;
		return;
	}

	int managerCount = 0, salesmanCount = 0, engineerCount = 0, specialistCount = 0;

	for (int i = 0; i < count; i++)
	{
		if (employees[i] != nullptr)
		{
			if (dynamic_cast<CSpecialistEmployee*>(employees[i]) != nullptr)
				specialistCount++;
			else if (dynamic_cast<CManagerEmployee*>(employees[i]) != nullptr)
				managerCount++;
			else if (dynamic_cast<CSalesmanEmployee*>(employees[i]) != nullptr)
				salesmanCount++;
			else if (dynamic_cast<CEngineerEmployee*>(employees[i]) != nullptr)
				engineerCount++;
		}
	}

	cout << "\nEmployee statistic : \n" << endl;
	cout << "Total Employees: " << count << endl;
	cout << "  Managers: " << managerCount << endl;
	cout << "  Salesmen: " << salesmanCount << endl;
	cout << "  Engineers: " << engineerCount << endl;
	cout << "  Specialists: " << specialistCount << endl;
}