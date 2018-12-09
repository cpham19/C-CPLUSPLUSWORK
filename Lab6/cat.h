#ifndef CAT_H
#define CAT_H

#include <string>
#include <iostream>
#include "predator.h"

using namespace std;

class Cat : public Predator {
public:
    Cat(string nameIn, double weightIn);
    void predate(Prey &prey);
    void call();
    friend ostream &operator<<(ostream &output, const Cat &cat);
};

#endif

