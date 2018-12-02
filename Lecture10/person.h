#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    public:
        double getShoeSize() const;
        std::string getName() const;
        void setShoeSize(double sizeIn);
        void setName(std::string nameIn);

    private:
        double shoeSize;
        std::string name;
};


#endif


