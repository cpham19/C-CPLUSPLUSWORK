#include "predator.h"

Predator::Predator(string nameIn, double weightIn) : Animal(nameIn, weightIn) {

}

void Predator::predate(Prey &prey) {
    cout << "I don't predate from anything because I'm generic." << endl;
}