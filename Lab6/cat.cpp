#include "cat.h"

Cat::Cat(string nameIn, double weightIn) : Predator(nameIn, weightIn) {
};

void Cat::predate(Prey &prey) {
    cout << getName() << " pounces and eats " << prey.getName() << ", who weights " << prey.getWeight() << " grams!" << endl;
}

void Cat::call() {
    cout << getName() << " says Meow meow!" << endl;
}

ostream &operator<<(ostream &output, const Cat &cat) {
    output << cat.getName() << " is a cat and weighs " << cat.getWeight() << " grams.";

    return output; // enables cascading
}