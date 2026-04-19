#include "CSpecialistEmployee.h"
#include <iostream>
#include <iomanip>
using namespace std;

CSpecialistEmployee::CSpecialistEmployee()
	: CManagerEmployee(), CSalesmanEmployee(), specialistBonus(0.0)
{
	name = "Specialist";
	hour_rate = 0.0;
}

CSpecialistEmployee::CSpecialistEmployee(string name, double hour_rate,
	int numOfWorkers, int numOfSoldItems, double bonus)
	: CManagerEmployee(name, hour_rate, numOfWorkers),
	CSalesmanEmployee(name, hour_rate, numOfSoldItems),
	specialistBonus(bonus)
{
	this->name = name;
	this->hour_rate = hour_rate;
	this->numOfWorkers = numOfWorkers;
	this->numOfSaledItem = numOfSoldItems;
}

CSpecialistEmployee::~CSpecialistEmployee() {}

void CSpecialistEmployee::PrintName() const
{
	cout << "Specialist (Manager + Salesman): " << name << endl;
}

double CSpecialistEmployee::CalculateSalaryForHours(double dWorkedHours) const
{
	double managerSalary = CManagerEmployee::CalculateSalaryForHours(dWorkedHours);
	double salesmanSalary = CSalesmanEmployee::CalculateSalaryForHours(dWorkedHours);

	return (managerSalary + salesmanSalary) / 2.0 + specialistBonus;
}

void CSpecialistEmployee::DisplayInfo() const
{
	cout << "Role: Specialist" << endl;
	cout << "Name: " << name << endl;
	cout << "Hour Rate: $" << fixed << setprecision(2) << hour_rate << "/hour" << endl;
	cout << "Workers Managed: " << numOfWorkers << endl;
	cout << "Products Sold: " << numOfSaledItem << endl;
	cout << "Specialist Bonus: $" << fixed << setprecision(2) << specialistBonus << endl;
	cout << "Combined Salary (40 hours): $" << fixed << setprecision(2) 
		<< CalculateSalaryForHours(40) << endl;
	cout << endl;
}

double CSpecialistEmployee::GetManagerSalary(double hours) const
{
	return CManagerEmployee::CalculateSalaryForHours(hours);
}

double CSpecialistEmployee::GetSalesmanSalary(double hours) const
{
	return CSalesmanEmployee::CalculateSalaryForHours(hours);
}

void CSpecialistEmployee::DisplayCompleteInfo() const
{

	cout << "\nSpecialist employee\n" << endl;

	cout << "\nBasic info:" << endl;
	cout << "Name: " << name << endl;
	cout << "Hour Rate: $" << fixed << setprecision(2) << hour_rate << "/hour" << endl;

	cout << "\nManager role:" << endl;
	cout << "Workers Managed: " << numOfWorkers << endl;
	cout << "Manager Productivity Score: " << CManagerEmployee::GetProductivityScore() << "/100" << endl;

	cout << "\nSalesman role:" << endl;
	cout << "Products Sold: " << numOfSaledItem << endl;
	cout << "Salesman Productivity Score: " << CSalesmanEmployee::GetProductivityScore() << "/100" << endl;

	cout << "\nSpecialist bonus" << endl;
	cout << "Special Bonus: $" << fixed << setprecision(2) << specialistBonus << endl;

	cout << "\nSalary calculation:" << endl;
	cout << "    Manager Salary (CManagerEmployee::CalculateSalaryForHours): $" 
		<< fixed << setprecision(2) << GetManagerSalary(40) << endl;
	cout << "    Salesman Salary (CSalesmanEmployee::CalculateSalaryForHours): $" 
		<< fixed << setprecision(2) << GetSalesmanSalary(40) << endl;

	cout << "    Combined Specialist Salary: $" 
		<< fixed << setprecision(2) << CalculateSalaryForHours(40) << endl;
}