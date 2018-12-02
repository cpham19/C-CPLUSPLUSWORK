#ifndef CIRCLE_H
#define CIRCLE_H

class Circle2 {
public:
    Circle2(double radiusIn);
    double getArea() const;
    bool operator==(const Circle2 &other);
    Circle2 operator+(const Circle2 &other);
private:
    double radius;
};

#endif

