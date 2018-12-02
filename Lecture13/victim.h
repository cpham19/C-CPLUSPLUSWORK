#ifndef VICTIM_H
#define VICTIM_H

#include <queue>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Victim {
    friend ostream &operator<<(ostream &output, const Victim &v);
public:
    Victim(string nameIn, int intelligenceIn, int appearanceIn);
    string getName() const;
    int getIntelligence() const;
    int getAppearance() const;

private:
    string name;
    int intelligence;
    int appearance;
};

ostream &operator<<(ostream &output, const Victim &v) {
    output << v.getName() << "; Intelligence: " << v.getIntelligence() << "; Appearance: " << v.getAppearance();
    return output;
}

#endif