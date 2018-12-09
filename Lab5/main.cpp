#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "payrollsystem.h"
#include "paycheck.h"

using namespace std;

int main() {
    PayrollSystem *ps = new PayrollSystem();
    ps->setNameOfCompany("Company #1");
    
    cout << "ADDED 4 EMPLOYEES" << endl;
    ps->addEmployee("E1234", "Calvin", "Pham", 10.50, 30);
    ps->addEmployee("E1235", "Paul", "French", 10.11, 47);
    ps->addEmployee("E1236", "Leonard", "Obay", 9.53, 25);
    ps->addEmployee("E1237", "Jaime", "Borunda", 10.00, 45);
    ps->printEmployees();
    
    cout << endl;
    
    cout << "REMOVING ONE EMPLOYEE" << endl;
    ps->removeEmployeeById("E1234");
    cout << endl;
    ps->printEmployees();
    
    cout << endl;
    
    cout << "SETTING HOURS FOR ONE EMPLOYEE TO 10" << endl;
    ps->recordEmployeeHoursById("E1236", 10);
    ps->printEmployees();
    
    cout << endl;
    ps->issuePaycheck();
    
    cout << endl;
    
    ps->printEmployees();
    
    return 0;
}

