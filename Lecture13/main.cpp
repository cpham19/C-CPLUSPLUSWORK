#include <cstdlib>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <string>
#include <set>
#include "vampire.h"
#include "map.h"
#include "mapentry.h"
#include "victim.h"

using namespace std;

ostream &operator<<(ostream &output, const Vampire &v) {
    output << v.name << " is a Vampire whose fangs are " << v.toothSize << " inches long.";

    return output; // enables cascading
}

// Returns index of the max element in the vector

template <class T>
int max(vector<T> ts) {
    if (ts.size() == 0) {
        return -1;
    } else if (ts.size() == 1) {
        return 0;
    }
    int max = 0;
    for (int counter = 1; counter < (int) ts.size(); counter++) {
        if (ts[counter] > ts[max]) {
            max = counter;
        }
    }
    return max;
}

// Returns index of the min element in the vector

template <class T>
int min(vector<T> ts) {
    if (ts.size() == 0) {
        return -1;
    } else if (ts.size() == 1) {
        return 0;
    }
    int max = 0;
    for (int counter = 1; counter < (int) ts.size(); counter++) {
        if (ts[counter] < ts[max]) {
            max = counter;
        }
    }
    return max;
}

Victim::Victim(string nameIn, int intelligenceIn, int appearanceIn) : name(nameIn), intelligence(intelligenceIn), appearance(appearanceIn) {
}

string Victim::getName() const {
    return name;
}

int Victim::getIntelligence() const {
    return intelligence;
}

int Victim::getAppearance() const {
    return appearance;
}

class CompareVictimsByIntel {
public:

    bool operator()(Victim &l, Victim &r) {
        if (l.getIntelligence() < r.getIntelligence()) {
            return true;
        }

        return false;
    }
};

class CompareVictimsByAppearance {
public:

    bool operator()(Victim &l, Victim &r) {
        if (l.getAppearance() < r.getAppearance()) {
            return true;
        }

        return false;
    }
};

double division(int a, int b) {
    if (b == 0) {
        throw "Division by zero condition!";
    }
    return (a / b);
}

const int NUMSWINGS = 2;

int main() {
    cout << "Template functions" << endl;
    vector<int> ints;
    ints.push_back(9);
    ints.push_back(7);
    ints.push_back(42);
    for (int i : ints) {
        cout << i << endl;
    }
    cout << "Smallest number in int vector: " << ints[min(ints)] << endl;
    cout << "Biggest number in int vector: " << ints[max(ints)] << endl;

    vector<Vampire> vs;
    vs.push_back(Vampire("Arthur", 2.2));
    vs.push_back(Vampire("Betty", 2.7));
    vs.push_back(Vampire("Cathy", 2.12));
    cout << "Smallest fang size: " << vs[max(vs)] << endl;
    cout << "Biggest fang size: " << vs[min(vs)] << endl;
    cout << endl;

    // Map
    cout << "Map" << endl;
    // test Map with double and int
    Map<double, int> m;
    // one way to add an entry
    m.addEntry(3.14, 3);
    // another way
    // addEntry is a function call, so this does not leave the entry on the stack
    m.addEntry(MapEntry<double, int>(1.99, 2));
    // a third way
    MapEntry<double, int> *a = new MapEntry<double, int>(4.56, 5);
    m.addEntry(*a);
    // a fourth way
    MapEntry <double, int> *b = new MapEntry<double, int>;
    b->setKey(6.66);
    b->setValue(7);
    m.addEntry(*b);

    // test for dupes:
    m.addEntry(3.14, 3);
    m.addEntry(MapEntry<double, int>(1.99, 2));
    MapEntry <double, int> *c = new MapEntry<double, int>(4.56, 5);
    m.addEntry(*c);
    cout << m;

    // test dictionary
    typedef Map<string, string> Dictionary;
    Dictionary d;
    d.addEntry(MapEntry<string, string>("Ameliorate", "Make better"));
    MapEntry <string, string> *g = new MapEntry<string, string>;
    g->setKey("Exacerbate");
    g->setValue("Make worse");
    d.addEntry(*g);
    d.addEntry("Aggravate", "Plagiarize code");
    cout << d;

    cout << endl;

    // Iterator example
    cout << "Iterator example" << endl;
    vector<char> container;

    container.push_back('A');
    container.push_back('B');
    container.push_back('C');
    container.push_back('D');

    for (int i = 0; i < 4; i++) {
        cout << "container[" << i << "] == " << container[i] << endl;
    }

    vector<char>::iterator p = container.begin();
    cout << "The third entry is " << container[2] << endl;
    cout << "The third entry is " << p[2] << endl;
    cout << "The third entry is " << *(p + 2) << endl;
    cout << endl;

    cout << "Back to container[0]." << endl;
    p = container.begin();
    cout << "Which has value " << *p << endl;

    cout << "Two steps forward and one step back." << endl;
    p++;
    p++;
    p--;
    cout << *p << endl;

    // Reverse order
    cout << "Reverse iterator" << endl;
    vector<char>::reverse_iterator ri;
    for (ri = container.rbegin(); ri != container.rend(); ri++) {
        cout << *ri << " ";
    }
    cout << endl;
    cout << endl;

    cout << "STL QUEUE" << endl;
    string currSwing;
    int turn = 0;
    queue <string> q;
    q.push("Ann");
    q.push("Barry");
    q.push("Cathy");
    q.push("Doug");
    q.push("Emily");
    q.push("Fred");

    string swings[NUMSWINGS] = {"Swing 1", "Swing 2"};
    while (!q.empty()) {
        currSwing = swings[turn % NUMSWINGS];
        cout << q.front() << " gets a turn on " << currSwing << endl;
        q.pop();
        turn++;
    }

    cout << endl;

    cout << "STL PriorityQueue" << endl;
    priority_queue<int> c1;
    c1.push(5);
    cout << "Pushing 5, size of C1 is " << c1.size() << endl;
    ;

    priority_queue<int> c2(c1);
    cout << "Copied C1 to C2, size of C2 is " << c2.size() << endl;
    ;

    cout << endl;

    vector<int> vec = {3, 1, 4, 1, 5};
    priority_queue<int> c3(less<int>(), vec);

    cout << "Copied a new int vec to C3 and used sort method. Size of C3 is " << c3.size() << endl;
    while (c3.size() > 0) {
        cout << c3.top() << endl;
        c3.pop();
    }
    cout << endl;

    cout << "Victim example" << endl;
    priority_queue <Victim, vector<Victim>, CompareVictimsByIntel> queue;
    queue.push(Victim("Medusa", 6, 2));
    queue.push(Victim("Aphrodite", 9, 10));
    queue.push(Victim("Hephaestus", 9, 1));
    queue.push(Victim("Neptune", 7, 4));

    cout << "Zombie attacks victims in descending order of intelligence: " << endl;
    while (queue.size() > 0) {
        cout << queue.top() << endl;
        queue.pop();
    }

    priority_queue <Victim, vector<Victim>, CompareVictimsByAppearance> q2;
    q2.push(Victim("Medusa", 6, 2));
    q2.push(Victim("Aphrodite", 9, 10));
    q2.push(Victim("Hephaestus", 9, 1));
    q2.push(Victim("Neptune", 7, 4));

    cout << "Vampire attacks victims in descending order of appearance: " << endl;
    while (q2.size() > 0) {
        cout << q2.top() << endl;
        q2.pop();
    }
    cout << endl;

    // Exception Handling
    cout << "Exception Handling" << endl;
    int x = 50;
    int y;
    double z = 0;

    do {
        cout << "Please enter divisor, -1 to quit: ";
        cin >> y;
        try {
            z = division(x, y);
            cout << z << endl;
        }        catch (const char* msg) {
            cerr << msg << endl;
        }
    } while (y != -1);

    cout << endl;

    cout << "Set" << endl;
    cout << endl;
   
    set<string> s;
    s.insert("Cathy");
    s.insert("Barry");
    s.insert("Andy");
    s.insert("Doug");
    
    cout << "Added four people, going through the list." << endl;

    set<string>::iterator i; // bidirectional
    for (i = s.begin(); i != s.end(); i++) {
        cout << *i << endl;
    }
    
    cout << endl;
    cout << "Reverse iteration" << endl;
    
    do {
        i--;
        cout << *i << endl;
    } while (i != s.begin());
    
    cout << endl;
    
    cout << "Go to the location of 'Barry'" << endl;
    i = s.find("Barry");
    cout << *i << endl;
    
    cout << "Go forward from location of 'Barry'" << endl;
    i++;
    cout << *i << endl;
    
    cout << endl;

    cout << "First person in the set" << endl;
    set<string>::const_iterator ci = s.begin();
    cout << *ci << endl;
    //*ci = "Ernie";		// invalid with const iterator
    
    cout << endl;

    cout << "Using Iterator in vector" << endl;
    vector<string> v;
    vector<string>::iterator r; // random access
    v.push_back("Cathy");
    v.push_back("Barry");
    v.push_back("Andy");
    v.push_back("Doug");

    r = v.begin();

    for (int counter = 0; counter < (int) v.size(); counter++) {
        cout << *(r + counter) << endl;
    }
    
    cout << endl;

    cout << "Step forward from Cathy's postion using preincremenental operator." << endl;
    cout << *(++r) << endl;

    return 0;
}

