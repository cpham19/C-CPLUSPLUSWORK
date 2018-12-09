#include "payrollsystem.h"
#include "paycheck.h"
#include <iostream>

using namespace std;

PayrollSystem::PayrollSystem() {
    
}

string PayrollSystem::getNameOfCompany() const {
    return nameOfCompany;
}

void PayrollSystem::setNameOfCompany(string name) {
    nameOfCompany = name;
}

void PayrollSystem::addEmployee(string id, string fName, string lName, double wage, int hours) {
    payrollList.push_back(Employee(id, fName, lName, wage, hours));
}

void PayrollSystem::recordEmployeeHoursById(string id, int hours) {
    for (int i = 0; i < (int) payrollList.size(); i++) {
        if (payrollList[i].getEmployeeId().compare(id) == 0) {
            payrollList[i].setNumberOfHours(hours);
        }
    }
}

void PayrollSystem::removeEmployeeById(string id) {
    for (int i = 0; i < (int) payrollList.size(); i++) {
        if (payrollList[i].getEmployeeId().compare(id) == 0) {
            payrollList.erase(payrollList.begin() + i);
        }
    }
}

void PayrollSystem::printEmployees() const{
    for (Employee e: payrollList) {
        cout << "Employee #" << e.getEmployeeId() << " " << e.getFirstName() <<  " " << e.getLastName() << " with hourly wage of $" << e.getHourlyWage() << " and " << e.getNumberOfHours() << " hours." << endl; 
    }
}

void PayrollSystem::issuePaycheck() {
    cout << "Payroll for " << nameOfCompany << ":" << endl;
    for (int i = 0; i < (int) payrollList.size(); i++) {
        Paycheck p = Paycheck(payrollList[i].getEmployeeId(), payrollList[i].getFirstName(), payrollList[i].getLastName(), payrollList[i].calcPay());
        payrollList[i].setNumberOfHours(0);
        cout << p << endl;
    }
}

ostream &operator<<(ostream &output, const Paycheck &p) {
    output << "Paycheck for $" << p.getPayCheckAmount() << " issued to " << p.getEmployeeId() <<  " " << p.getFirstName() << " " << p.getLastName() << ".";

    return output; // enables cascading
}

vector<Employee> PayrollSystem::getPayrollList() const {
    return payrollList;
}