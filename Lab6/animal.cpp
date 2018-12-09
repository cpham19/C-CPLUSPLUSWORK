#include "animal.h"

Animal::Animal(string nameIn, double weightIn) : name(nameIn), weight(weightIn) {

}

void Animal::eat(double weightOfFood) {

}

string Animal::getName() const {
    return name;
}

double Animal::getWeight() const {
    return weight;
}