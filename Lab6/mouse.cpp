#include "mouse.h"

Mouse::Mouse(string nameIn, double weightIn) : Prey(nameIn, weightIn) {
    
}

void Mouse::call() {
    cout << getName() << " says squeek!" << endl;
}

void Mouse::flee() {
    cout << getName() << " scurries away!" << endl;
}