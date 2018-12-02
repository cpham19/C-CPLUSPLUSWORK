#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BaseClass {
public:

    BaseClass() : baseValue(20) {
    };

    BaseClass(int aValue) : baseValue(aValue) {
    };

    int getBaseValue() const {
        return baseValue;
    }
protected:
    int baseValue;
};

class DerivedClass : public BaseClass {
public:

    DerivedClass() : derivedValue(10) {
    };

    DerivedClass(int baseValue, int aDerivedValue) : BaseClass(baseValue), derivedValue(aDerivedValue) {
    };

    int getDerivedValue() const {
        return derivedValue;
    }

    int getBaseValue() const {
        return baseValue;
    }
private:
    int derivedValue;
};

class Person {
public:
    string m_name;
    int m_age;

    string getName() const {
        return m_name;
    }

    int getAge() const {
        return m_age;
    }

    Person(string name = "", int age = 0)
    : m_name(name), m_age(age) {
    }
};

// Employee publicly inherits from Person

class Employee : public Person {
public:
    double m_hourlySalary;
    long m_employeeID;

    Employee(double hourlySalary = 0.0, long employeeID = 0)
    : m_hourlySalary(hourlySalary), m_employeeID(employeeID) {
    }

    void printNameAgeAndSalary() const {
        cout << m_name << "(" << m_age << "): " << m_hourlySalary << '\n';
    }
};

class Animal {
public:

    //    void eat() {
    //        cout << "I'm eating generic food.\n";
    //    }
    // correct by making this function virtual:

    virtual void eat() {
        cout << "I'm eating generic food.\n";
    }
};

class Cat : public Animal {
public:

    void eat() {
        cout << "I'm eating a rat.\n";
    }
};

class Dog : public Animal {
public:

    void eat() {
        cout << "I'm eating canned food.\n";
    }
};

void func(Animal *xyz) {
    xyz->eat();
}

class Monster {
public:

    Monster(string nameIn) : name(nameIn) {
    }
    virtual void rampage() = 0;

    string getName() const {
        return name;
    }
private:
    string name;
};

class Zombie : public Monster {
public:

    Zombie(string nameIn) : Monster(nameIn) {
    };

    void rampage() {
        cout << getName() << " joins a herd of zombies searching for brains." << endl;
    }
};

class Vampire : public Monster {
public:

    Vampire(string nameIn) : Monster(nameIn) {
    };

    void rampage() {
        cout << getName() << " turns into a bat and flies through your window to suck your blood." << endl;;
    }
};

int main() {
    BaseClass base;
    BaseClass base2(150);

    cout << "Inheritance Example #1" << endl;
    cout << "Base #1 (no parameter): " << base.getBaseValue() << endl;
    cout << "Base #2 (with parameter) " << base2.getBaseValue() << endl;

    DerivedClass child;
    DerivedClass child2(42, 5);
    cout << "Child #1 (no parameter) Base Value: " << child.getBaseValue() << endl;
    cout << "Child #1 (no parameter) Derived Value: " << child.getDerivedValue() << endl;
    cout << "Child #2 (with parameter) Base Value: " << child2.getBaseValue() << endl;
    cout << "Child #2 (with parameter) Derived Value: " << child2.getDerivedValue() << endl;
    cout << endl;

    cout << "Inheritance example #2" << endl;
    Employee frank(20.25, 12345);
    frank.m_name = "Frank"; // we can do this because m_name is public
    frank.m_age = 30;
    frank.printNameAgeAndSalary();
    cout << endl;

    cout << "Virtual Functions" << endl;
    Animal *animal = new Animal;
    Cat *cat = new Cat;
    Dog *dog = new Dog;

    // outputs: "I'm eating generic food."
    animal->eat();
    // outputs: "I'm eating a rat."
    cat->eat();
    // outputs: "I'm eating a dog."
    dog->eat();

    // note that parameter type of func is Animal.
    // outputs: "I'm eating generic food."
    func(animal);
    // outputs "I'm eating a rat."
    // outputs: "I'm eating generic food." IF base function is not virtual
    func(cat);
    // outputs "I'm eating canned food."
    func(dog);
    cout << endl;

    cout << "Pure Virtual Functions" << endl;
    Monster *x = new Vampire("X"); // OK
    //Monster *y = new Monster("Y");    // error: Monster is abstract

    vector<Monster *> monsters;
    monsters.push_back(new Zombie("Zelda"));
    monsters.push_back(new Zombie("Zaphrod"));
    monsters.push_back(new Vampire("Vinnie"));
    monsters.push_back(new Vampire("Von"));

    for (Monster *m : monsters) {
        m->rampage();
    }
    
    cout << endl;
    
    cout << "Random Number" << endl;
    // seed number from system clock
    srand(time(NULL));
    
    //rand() generates an int
    double f = (double)rand() / RAND_MAX;
    cout << f << endl;
    
    // numbers between 1 and 10 (inclusive)
    int i =  (rand() % 10) + 1;
    
    while (i != 10) {
        i = (rand() % 10) + 1;
        cout << i << endl;
    }

    return 0;
}

