#ifndef PAYROLLSYSTEM_H
#define PAYROLLSYSTEM_H

#include <vector>
#include <string>
#include "employee.h"
#include "paycheck.h"

using namespace std;

class PayrollSystem {
    public:
        PayrollSystem();
        string getNameOfCompany() const;
        void setNameOfCompany(string name);
        void addEmployee(string id, string fName, string lName, double wage, int hours);
        void recordEmployeeHoursById(string id, int hours);
        void removeEmployeeById(string id);
        void printEmployees() const;
        void issuePaycheck();
        vector<Employee> getPayrollList() const;

    private:
        string nameOfCompany;
        vector<Employee> payrollList;
};

#endif /* PAYROLLSYSTEM_H */

