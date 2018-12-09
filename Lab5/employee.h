#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
    public:
        Employee(string id, string fName, string lName, double wage, int hours );
        string getEmployeeId() const;
        string getFirstName() const;
        string getLastName() const;
        string getFullName() const;
        double getHourlyWage() const;
        int getNumberOfHours() const;
        void setNumberOfHours(int hours);
        double calcPay() const;

    private:
        string employeeId;
        string firstName;
        string lastName;
        double hourlyWage;
        int numberOfHours;
};

#endif