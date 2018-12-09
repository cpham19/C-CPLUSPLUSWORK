#include "prey.h"

Prey::Prey(string nameIn, double weightIn) : Animal(nameIn, weightIn) {
    
}

void Prey::flee() {
    cout << "I don't flee from anything because I'm generic." << endl;
}