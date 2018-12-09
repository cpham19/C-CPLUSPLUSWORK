#include "bird.h"

Bird::Bird(string nameIn, double weightIn) : Prey(nameIn, weightIn) {
    
}

void Bird::call() {
    cout << getName() << " says tweet!" << endl;
}

void Bird::flee() {
    cout << getName() << " flies away!" << endl;
}