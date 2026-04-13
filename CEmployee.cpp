#include "CEmployee.h"
#include <iostream>
using namespace std;

CEmployee::CEmployee() : name("Worker"), hour_rate(0) {}

CEmployee::CEmployee(std::string m_name, double m_hour_rate) : name(m_name), hour_rate(m_hour_rate) {}

CEmployee::~CEmployee() {}