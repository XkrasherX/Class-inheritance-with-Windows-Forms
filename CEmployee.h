#pragma once
#include <iostream>
using namespace std;

class CEmployee {
public:
	void PrintName();
	double calulateSalryForHimself(int numOfItems);
};

class CManagerEmployee : public CEmployee {
protected:
	int numOfWorkers;
};

class CSalesmanEmployee : protected CEmployee {
protected:
	int numOfSaledItem;

};

class CEngineerEmployee : public CEmployee {
protected:
	int numOfFixedDetails;

};

double CalculateSalaryForHours(const double dWorkedHours);