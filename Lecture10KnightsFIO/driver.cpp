#include <iostream>
#include <fstream>
#include <vector>
#include "knight.h"
#include "knightstorage.h"

using namespace std;

int main() {
    int choice;
    KnightStorage s;
    cout << "Enter 1 to write to file, 2 to read from file " << endl;
    cin >> choice;
    if (choice == 1) {
        s.writeHardCodedKnights();
    }
    if (choice == 2) {
        for (Knight k : s.readFromFile()) {
            k.showAnswers();
        }
    }
    return 0;

}

