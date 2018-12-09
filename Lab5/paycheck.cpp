#include "paycheck.h"

Paycheck::Paycheck(string id, string fName, string lName, double pay) : employeeId(id), firstName(fName), lastName(lName), paycheckAmount(pay) {
}

string Paycheck::getEmployeeId() const {
    return employeeId;
}

string Paycheck::getFirstName() const {
    return firstName;
}

string Paycheck::getLastName() const {
    return lastName;
}

double Paycheck::getPayCheckAmount() const {
    return paycheckAmount;
}

