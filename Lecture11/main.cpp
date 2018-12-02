#include <cstdlib>
#include <string>
#include <cmath>
#include <iostream>
#include "circle.h"
#include <iomanip>
#include "date.h"

using namespace std;

const double PI = 3.142;

class Rectangle; // declaration so class will be available for use in Circle definition 

class Circle {
    friend void resizeCircleMatchRectangle(Circle *c, Rectangle *r);
public:

    Circle(double radiusIn) {
        radius = radiusIn;
    }

    double getArea() const {
        return PI * radius * radius;
    }

private:
    double radius;
};

class Rectangle {
    friend void resizeCircleMatchRectangle(Circle *c, Rectangle *r);
public:

    Rectangle(double lengthIn, double widthIn) {
        length = lengthIn;
        width = widthIn;
    }

    double getArea() const {
        return length * width;
    }

private:
    double length;
    double width;
};

//resize a Circle so it has the same area as a supplied Rectangle

void resizeCircleMatchRectangle(Circle *c, Rectangle *r) {
    double area = r->length * r->width; // could also have used getArea()
    double newRadius = sqrt(area / PI);
    c->radius = newRadius;
}

Circle2::Circle2(double radiusIn) : radius(radiusIn) {
}

double Circle2::getArea() const {
    return M_PI * pow(radius, 2);
}

bool Circle2::operator==(const Circle2 &other) {
    cout << "called " << endl;
    if (abs(other.radius - radius) < 0.0001) {
        return true;
    } else {
        return false;
    }
}

Circle2 Circle2::operator+(const Circle2 &other) {
    double combinedArea = M_PI * pow(radius, 2) + other.getArea();
    double newRadius = sqrt(combinedArea / M_PI);
    return Circle2(newRadius);
}

//class PhoneNumber {
//    friend ostream &operator<<(ostream&, const PhoneNumber &);
//    friend istream &operator>>(istream&, PhoneNumber &);
//private:
//    // 3-digit area code and null
//    char areaCode[ 4 ];
//    // 3-digit exchange and null
//    char exchange[ 4 ];
//    // 4-digit line and null
//    char line[ 5 ];
//};
//
//// Overloaded stream-insertion operator (cannot be 
//// a member function if we would like to invoke it with
//// cout << somePhoneNumber;) cout is not an instance of PhoneNumber.
//
//ostream &operator<<(ostream &output, const PhoneNumber &num) {
//    output << "(" << num.areaCode << ") " << num.exchange << "-" << num.line;
//
//    // enables cout << a << b << c;
//    return output;
//}
//
//istream &operator>>(istream &input, PhoneNumber &num) {
//    input.ignore(); // skip (
//    input >> setw(4) >> num.areaCode; // input area code
//    input.ignore(2); // skip ) and space
//    input >> setw(4) >> num.exchange; // input exchange
//    input.ignore(); // skip dash (-)
//    input >> setw(5) >> num.line; // input line
//    return input; // enables cin >> a >> b >> c;
//}

// Initialize static member at file scope; 
// one class-wide copy.
const int Date::days[] = {0, 31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31};

// Date constructor

Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

// Set the date

void Date::setDate(int mm, int dd, int yy) {
    month = (mm >= 1 && mm <= 12) ? mm : 1;
    year = (yy >= 1900 && yy <= 2100) ? yy : 1900;

    // test for a leap year
    if (month == 2 && leapYear(year))
        day = (dd >= 1 && dd <= 29) ? dd : 1;
    else
        day = (dd >= 1 && dd <= days[ month ]) ? dd : 1;
}

// Preincrement operator overloaded as a member function.
Date &Date::operator++() {
    helpIncrement();
    return *this; // reference return to create an lvalue
}

// Postincrement operator overloaded as a member function.
// Note that the dummy integer parameter does not have a
// parameter name.

Date Date::operator++(int) {
    Date temp = *this;
    helpIncrement();

    // return non-incremented, saved, temporary object
    return temp; // value return; not a reference return
}

// Add a specific number of days to a date
const Date &Date::operator+=(int additionalDays) {
    for (int i = 0; i < additionalDays; i++) {
        helpIncrement();
    }

    return *this; // enables cascading
}

// If the year is a leap year, return true; 
// otherwise, return false

bool Date::leapYear(int y) const {
    if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
        return true; // a leap year
    else
        return false; // not a leap year
}

// Determine if the day is the end of the month

bool Date::endOfMonth(int d) const {
    if (month == 2 && leapYear(year))
        return d == 29; // last day of Feb. in leap year
    else
        return d == days[ month ];
}


// Function to help increment the date
void Date::helpIncrement() {
    if (endOfMonth(day) && month == 12) { // end year
        day = 1;
        month = 1;
        ++year;
    }
    else if (endOfMonth(day)) { // end month
        day = 1;
        ++month;
    }
    else // not end of month or year; increment day
        ++day;
}

// Overloaded output operator
ostream &operator<<(ostream &output, const Date &d) {
    static string monthName[ 13 ] = {"", "January",
        "February", "March", "April", "May", "June",
        "July", "August", "September", "October",
        "November", "December"};

    output << monthName[ d.month ] << ' ' << d.day << ", " << d.year;

    return output; // enables cascading
}

int main() {
    cout << "Friend Function" << endl;
    Circle *c = new Circle(5.0);
    Rectangle *r = new Rectangle(6.0, 7.0);
    cout << "area of circle: " << c->getArea() << " size of rectangle: " << r->getArea() << endl;
    resizeCircleMatchRectangle(c, r);
    cout << "area of circle: " << c->getArea() << " size of rectangle: " << r->getArea() << endl;
    cout << endl;

    cout << "Operator overloading" << endl;
    Circle2 *c1 = new Circle2(5.0);
    Circle2 *c2 = new Circle2(4.7);
    Circle2 *c3 = new Circle2(4.7);

    cout << "area of c1: " << c1->getArea() << endl;
    cout << " area of c2: " << c2->getArea() << endl;
    cout << " area of c3: " << c3->getArea() << endl;
    cout << "c1 == c2? " << (*c1 == *c2) << endl;
    cout << " c2 == c3? " << (*c2 == *c3) << endl;
    Circle2 c4 = *c1 + *c2; // have to put this on the stack; could copy it to the heap
    cout << "area of c4: " << c4.getArea() << endl;
    cout << endl;

    //    cout << "Overloading Stream-insertion and Stream-extraction operators" << endl;
    //    // create object phone
    //    PhoneNumber phone;
    //    cout << "Enter phone number in the form (123) 456-7890:\n";
    //
    //    // cin >> phone invokes operator>> function by 
    //    // issuing the call operator>>( cin, phone ).
    //    cin >> phone;
    //
    //    // cout << phone invokes operator<< function by
    //    // issuing the call operator<<( cout, phone ). 
    //    cout << "The phone number entered was: " << phone << endl;
    //    cout << endl;

    cout << "Overloading ++ and -- using Date class as class study" << endl;
    Date d1, d2(12, 27, 1992), d3(0, 99, 8045);
    cout << "d1 is " << d1 << endl;
    cout << "d2 is " << d2 << endl;
    cout << "d3 is " << d3 << endl;;

    cout << "d2 += 7 is " << (d2 += 7) << endl;;

    d3.setDate(2, 28, 1992);
    cout << "  d3 is " << d3 << endl;
    cout << "++d3 is " << ++d3 << endl;

    Date d4(3, 18, 1969);

    cout << "Testing the preincrement operator:" << endl;
    cout << "  d4 is " << d4 << endl;
    cout << "++d4 is " << ++d4 << endl;
    cout << "  d4 is " << d4 << endl;;

    cout << "Testing the postincrement operator:" << endl;
    cout << "  d4 is " << d4 << endl;
    cout << "d4++ is " << d4++ << endl;
    cout << "  d4 is " << d4 << endl;
    cout << "d4 += 3" << (d4 += 3) << endl;

    return 0;
}

