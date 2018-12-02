#include <iostream>
#include <fstream>
#include <vector>

#include "knight.h"
#include "knightstorage.h"

using namespace std;

void KnightStorage::writeHardCodedKnights() {
    ofstream myFile;
    string filePath;
    string line;
    vector<Knight> knights;

    Knight firstKnight(1, "Arthur", "I seek the Holy Grail", "Carotid Blue");
    Knight secondKnight(2, "Lancelot", "I seek the Holy Grail", "Jugular Red");
    Knight thirdKnight(3, "Lancelittle", "I seek the Holy Grail", "Gut Orange");
    knights.push_back(firstKnight);
    knights.push_back(secondKnight);
    knights.push_back(thirdKnight);

    cout << "Enter full file path: ";
    cin >> filePath;
    myFile.open(filePath);

    for (Knight k : knights) {
        myFile << k.getCSVString();
    }
    myFile.close();
}

vector <Knight> KnightStorage::readFromFile() {
    ifstream myFile;
    string filePath;
    string line;
    int num;
    string name, quest, favoriteColor;
    vector<string> tokens;

    cout << "Enter full file path: ";
    cin >> filePath;
    myFile.open(filePath);

    if (myFile.is_open()) {
        while (getline(myFile, line)) {

            tokens = tokenize(line);
            num = stoi(tokens[0]);
            Knight k(num, tokens[1], tokens[2], tokens[3]);
            knights.push_back(k);
            if (myFile.eof()) cout << "reached eof" << endl;
        }
        cout << knights.size() << endl;

        myFile.close();
    } else cout << "File open failed" << endl;
    cout << knights.size() << endl;
    return knights;

}

vector<string> KnightStorage::tokenize(string in) {
    // http://oopweb.com/CPP/Documents/CPPHOWTO/Volume/C++Programming-HOWTO-7.html
    vector<string> tokens;
    const string delimiter = ",";

    string::size_type lastPos = in.find_first_not_of(delimiter, 0);

    // Find first "non-delimiter".
    string::size_type pos = in.find_first_of(delimiter, lastPos);

    while (string::npos != pos || string::npos != lastPos) {
        // Found a token, add it to the vector.
        tokens.push_back(in.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = in.find_first_not_of(delimiter, pos);
        // Find next "non-delimiter"
        pos = in.find_first_of(delimiter, lastPos);
    }
    return tokens;
}
