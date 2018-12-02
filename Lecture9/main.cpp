#include <cstdlib>
#include <iostream>
#include <vector>
#include "Borg.h"

using namespace std;

// Another way to define a class and its functions
//class Name{
//	public:
//		void setLast(string in);
//		void setFirst(string in);
//		string getName() const;
//		
//	private:
//		string first;
//		string last;
//};
//void Name::setLast(string in){last = in;}
//void Name::setFirst(string in){first = in;}
//string Name:: getName() const{return last + ", " + first;}

class Name {
public:

        void setLast(string in) {
            last = in;
        };

        void setFirst(string in) {
            first = in;
        };

        string getName() const {
            return last + ", " + first;
        };

    private:
        string first;
        string last;
};

// Static variable
//class Borg {
//    public:
//        Borg(int ordinalIn);
//        void attack();
//        void stateName();
//        // static void stateBorgCount(); 
//        
//    private:
//        int ordinal;
//        static int borgCount;
//};

Borg::Borg(int ordinalIn) : ordinal(ordinalIn) {
    borgCount++;
}

void Borg::attack() {
    cout << ordinal << " of " << borgCount << " attacks " << endl;
}

void Borg::stateName(){
    cout << ordinal << " of " << borgCount << " attacks " << endl;
}

//static void Borg::stateBorgCount(){
//    cout << "There are currently " << borgCount << " Borg" << endl;
//}

int Borg::borgCount = 0;

int main() {
    // Making a class
    cout << "Defining a Class" << endl;
    Name n;
    n.setLast("Smith");
    n.setFirst("Winston");
    cout << n.getName() << endl;
    cout << endl;

    // Static variable
    cout << "Static variable and static method" << endl;
    const int NUM_BORG = 10;
    vector<Borg> borgs;
    for (int counter = 1; counter < NUM_BORG; counter++) {
        borgs.push_back(Borg(counter));
    }
    
    // enhanced for loop, just like in Java!
    for (Borg b : borgs) {
        b.attack();
        // b.stateBorgCount();
    }
    
    cout << endl;

    return 0;
}

