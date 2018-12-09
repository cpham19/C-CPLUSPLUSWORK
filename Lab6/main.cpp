#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "cat.h"
#include "bird.h"
#include "mouse.h"

using namespace std;

int main() {
    Cat *cat = new Cat("Arin", 350);
    cout << *cat << endl;
    cat->call();
    
    vector<Prey *> preys;
    preys.push_back(new Bird("Hawk", 123.5));
    preys.push_back(new Bird("Eagle", 512.2));
    preys.push_back(new Mouse("Mickie", 1234.5));
    preys.push_back(new Mouse("Minnie", 12233.5));
    
    srand(time(NULL));
    
    for (Prey *p : preys) {
        p->call();
        double f = (double)rand() / RAND_MAX;
        
        if (f < 0.5) {
            cat->predate(*p);
        }
        else {
            p->flee();
        }
    }

    return 0;
}

