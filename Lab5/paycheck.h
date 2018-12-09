#ifndef PAYCHECK_H
#define PAYCHECK_H

#include <string>
using namespace std;

class Paycheck {
    public:
        Paycheck(string id, string fName, string lName, double paycheckAmount);
        string getEmployeeId() const;
        string getFirstName() const;
        string getLastName() const;
        double getPayCheckAmount() const;
        friend ostream &operator<<(ostream &output, const Paycheck &p);
    private:
        string employeeId;
        string firstName;
        string lastName;
        double paycheckAmount;
};


#endif