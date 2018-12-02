#include "vampire.h"

Vampire::Vampire(string nameIn, double toothSizeIn) : name(nameIn), toothSize(toothSizeIn) {
}

string Vampire::getName() const {
    return name;
}

double Vampire::getToothSize() const {
    return toothSize;
}

bool Vampire::operator>(Vampire &other) {
    if (toothSize - other.toothSize > .001) {
        return true;
    }

    return false;
}

bool Vampire::operator<(Vampire &other) {
    if (toothSize - other.toothSize < .001) {
        return true;
    }

    return false;
}