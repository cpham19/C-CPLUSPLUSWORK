#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include "person.h"

using namespace std;

void myValueFunction(int x) {
    x = 500;
    return;
}

void myReferenceFunction(int& x) {
    x = 500;
    return;
}

void printTextFileContents(ifstream &inFile) {
    string line;
    while (!inFile.eof()) {
        getline(inFile, line);
        cout << line << endl;
    }
}

void myConstReferenceFunction(const int& x) {
    // x = 500; syntax error, can't change a const object
    return;
}

int& myFunction() {
    // x points to an int on the heap, not the stack
    int *x = new int(42);

    // *x is an int, but it is converted to a reference d/t the function header
    return *x;
}

// http://www.dummies.com/programming/cpp/returning-a-reference-from-a-function-in-c/

class DigInto {
private:
    int secret;
public:

    DigInto() {
        secret = 150;
    }

    int &GetSecretVariable() {
        return secret;
    }

    void Write() {
        cout << secret << endl;
    }
};

vector<int> getInts() {
    vector<int> v;

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    // OK; makes a copy of the vector header info, not a deep copy.
    return v;
}

int *otherFunction(int length) {
    int *a = new int[length];
    for (int counter = 0; counter < length; counter++)
        a[counter] = counter;
    return a;
}

// used with person.h

double Person::getShoeSize() const {
    return shoeSize;
}

string Person::getName() const {
    return name;
}

void Person::setShoeSize(double sizeIn) {
    shoeSize = sizeIn;
}

void Person::setName(string nameIn) {
    name = nameIn;
}

int main() {
    // Output
    ofstream outputFile;
    // Input
    ifstream inputFile;
    // Filepath user input
    string filePath;
    // Lines of textfile
    string line;

    // Output file
    cout << "Output example" << endl;
    cout << "Enter full file path: ";
    cin >> filePath;
    outputFile.open(filePath);

    // Error-checking
    if (outputFile.fail()) {
        cout << "outputFile open failed!" << endl;
    }
    if (!(outputFile.is_open())) {
        cout << "file is not open" << endl;
    } else {
        outputFile << "The rain in Spain falls mainly on the plain.\n";
        outputFile << "The heat in Nevada covers the land.\n";
        outputFile << "The chill in Sweden drenches the air.\n";
    }
    outputFile.close();
    cout << endl;

    // Input file
    cout << "Reading output file" << endl;
    inputFile.open(filePath);
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            // eof() returns a boolean end-of-file indicator
            getline(inputFile, line);
            cout << line << endl;
        }
    } else {
        cout << "File open failed" << endl;
    }
    inputFile.close();


    cout << "Reference example" << endl;
    int x = 42;
    cout << x << endl;
    myValueFunction(x);
    cout << x << endl;
    // can’t tell from this syntax that the method takes a reference!
    myReferenceFunction(x);
    cout << x << endl;
    cout << endl;

    cout << "Reference example #2" << endl;
    inputFile.open(filePath);
    if (inputFile.is_open()) {
        printTextFileContents(inputFile);
    } else {
        cout << "File open failed" << endl;
    }
    inputFile.close();


    // New example
    cout << "'New' example" << endl;
    int *n = new int;
    *n = 42;
    cout << *n << endl;
    cout << endl;

    // Array on heap
    cout << "Array on heap" << endl;
    int *values;
    const int ARRAYSIZE = 10;
    values = new int [ARRAYSIZE];
    for (int i = 0; i < ARRAYSIZE; i++) {
        *(values + i) = i;
    }

    for (int i = 0; i < ARRAYSIZE; i++) {
        cout << *(values + i) << endl;
        ;
    }
    cout << endl;

    // Returning a reference
    cout << "Returning a reference" << endl;
    int num1 = myFunction();
    cout << num1 << endl;
    cout << endl;

    // Returning a reference with private member
    cout << "Returning a reference to a private member" << endl;
    DigInto inst;
    inst.Write();
    int &pry = inst.GetSecretVariable();
    pry = 30;
    inst.Write();
    cout << endl;

    // Using delete to free heap space
    int *pointer = new int(42);
    delete pointer;
    pointer = nullptr;

    // memory example
    //    double *values;
    //    cout << "hit any key" << endl;
    //    getchar();
    //    values = new double[10000000];
    //    cin.ignore(1000, '\n');
    //    cout << "hit any key" << endl;
    //    getchar();
    //    delete[] values;
    //    values = nullptr;
    //    cin.ignore(1000, '\n');
    //    cout << "hit any key" << endl;
    //    getchar();

    // Returning a vector
    cout << "Returning a vector" << endl;
    vector<int> ints = getInts();
    for (int i : ints) {
        cout << i << endl;
    }
    cout << endl;

    // Returning a array
    cout << "Returning an array" << endl;
    int length = 10;
    int *b = otherFunction(length);
    for (int i = 0; i < length; i++) {
        cout << *(b + i) << endl;
    }
    cout << endl;

    // Pointers to member fields and functions
    //MyClass *p = new MyClass;
    //(*p).myFunction();
    //(*p).myVariable;

    // -> operator
    cout << "-> Operator example" << endl;
    Person *person = new Person(); 
    person->setName("Arthur");
    person->setShoeSize(10.5);
    cout << person->getName() << " wears size " << person->getShoeSize() << endl;
    cout << endl;
    
    // Destructor and Freeing memory
    // cout << "Freeing memory" << endl;
    
    //    MyClass::~MyClass(){
    //	// code here to delete any dynamically-allocated values
    //    }
    
    //  class A {
    //      public: 
    //		A(); // Constructor
    //		~A(); // Destructor
    //  };
    //
    //
    //  A::~A() {}


    // Deleting number and array
    int num2 = new int;
    num2 = 42;
    delete x;
    
    int *array = new int[10];
    delete[] array;

    return 0;
}

