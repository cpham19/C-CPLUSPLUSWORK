#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <string>
using namespace std;

class Vampire {
    public:
        Vampire(string nameIn, double toothSizeIn);
        string getName() const;
        double getToothSize() const;
        bool operator>(Vampire &other);
        bool operator<(Vampire &other);
        friend ostream &operator<<(ostream &output, const Vampire &v);
    private:
        string name;
        double toothSize;
};


#endif