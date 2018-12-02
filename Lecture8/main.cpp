#include <cstdlib>
#include <iostream> 
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// Namespaces (this would be declared in different files)
namespace a {

    void myFunction() {
        cout << "York!" << endl;
    }
}

namespace b {

    void myFunction() {
        cout << "Lancaster!" << endl;
    }
}

// Method overloadding

int sum(int a, int b) {
    return a + b;
}

double sum(double a, double b) {
    return a + b;
}

// Template methods

template <class T>
T sum(T a, T b) {
    T result;
    result = a + b;
    return result;
}

template <class T, int N>
T fixed_multiply(T val) {
    return val * N;
}

int main() {
    // Hello World
    std::cout << "Hello World example \n";
    string name;
    std::cout << "What is your name? ";
    std::cin >> name;
    std::cout << "Hello, " + name + "\n\n";

    // Alternative Declaration/Assignment Syntax
    std::cout << "Alternative Declaration and Assignment Syntax \n";
    int x{42};
    int y = 2.5;
    // int y{2.5}; syntax error
    std::cout << x;
    std::cout << "\n\n";

    // Namespaces
    // if you declare std at the top, you don't need to use the directive
    // you don't need std. you can use entities by declaring this way: std::cout << x;
    cout << "Namspaces \n";
    cout << "Hi" << endl;

    a::myFunction();
    b::myFunction();

    cout << endl;

    int a = 42;
    double b = 2.54;

    // endl is new line
    cout << "Cout examples" << endl;
    cout << "a = " << a << "; b = " << b << endl;
    cout << 'A' + 'B' << endl;
    // cout << 'A' + endl; doesnt work
    cout << "A" << endl;

    int q;
    double w;
    char r;

    cout << "enter an int, a double, and a char" << endl;
    cin >> q >> w >> r;
    cout << "your int: " << q << "; your double: " << w << "; your char: " << r << endl;

    // Flush newline character out of buffer
    // cin.ignore(num) ignores num characters
    // cin.ignore(1000, '\n') ignores input up to and including a newline, but not more than 1000 characters

    cin.ignore();

    cout << "Please enter a string: ";
    string s;
    getline(cin, s);
    cout << "your string: " << s << endl;
    cout << endl;

    cout << "Vector example" << endl;
    vector <int> v;
    cout << "size " << v.size() << " capacity " << v.capacity() << endl;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    cout << "New size and capacity after pushing items" << endl;
    cout << "size " << v.size() << " capacity " << v.capacity() << endl;
    cout << endl;

    // printing items in the vector
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Push the size of vector to the vector
    cout << "Pushing one item" << endl;
    v.push_back(v.size());
    cout << "size " << v.size() << " capacity " << v.capacity() << endl;
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    int currSize = (int) v.size();
    int currCap = (int) v.capacity();
    // Fill up the rest of the vector
    for (int i = currSize; i <= currCap; i++) {
        v.push_back(i);
    }

    // New capacity (automatically resize vector)
    cout << "size " << (int) v.size() << " capacity " << v.capacity() << endl;
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Change the first one
    cout << "Changing the first vector item" << endl;
    v[0] = 42;
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << endl;

    // Method overloading
    cout << "Overloading Methods" << endl;
    cout << sum(10, 20) << '\n';
    cout << sum(1.0, 1.5) << '\n';
    cout << endl;

    // Template Functions
    cout << "Template Methods" << endl;
    int i = 5, j = 6, k = sum<int>(i, j);
    double f = 2.0, g = 0.5, h = sum<double> (f, g);
    cout << k << '\n';
    cout << h << '\n';

    cout << fixed_multiply<int, 2>(10) << endl;
    cout << fixed_multiply<int, 3>(10) << endl;
    cout << endl;

    // C-strings and C++ strings
    char cString[] = "Earth is flat";
    string cppString;
    string cppString2;
    
    cppString = cString;
    cout << cppString << endl;
    // cString = cppString gives us error
    strncpy(cString, cppString2.c_str(), 30);
    cout << cppString2 << endl;
    
    return 0;
}

