#include "employee.h"

Employee::Employee(string id, string fName, string lName, double wage, int hours) : employeeId(id), firstName(fName), lastName(lName), hourlyWage(wage), numberOfHours(hours) {
}

string Employee::getEmployeeId() const {
    return employeeId;
}

string Employee::getFirstName() const {
    return firstName;
}

string Employee::getLastName() const {
    return lastName;
}

double Employee::getHourlyWage() const {
    return hourlyWage;
}

int Employee::getNumberOfHours() const {
    return numberOfHours;
}

void Employee::setNumberOfHours(int hours) {
    numberOfHours = hours;
}

double Employee::calcPay() const {
    return hourlyWage * numberOfHours;
}
