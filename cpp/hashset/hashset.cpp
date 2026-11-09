#include "hashset.h"
#include <iostream>
#include <sstream>
using namespace std;

void executeQuery(const string& filename, const string& query) {
    HashSet mySet;
    mySet.loadFromFile(filename);
    istringstream iss(query);
    string command, value;
    iss >> command;
    if (command == "SETADD") { iss >> value; mySet.add(value); cout << "Added: " << value << "\n"; }
    else if (command == "SETDEL") { iss >> value; if (mySet.del(value)) cout << "Deleted: " << value << "\n"; else cout << "Element not found\n"; }
    else if (command == "SET_AT") { iss >> value; cout << (mySet.at(value) ? "TRUE" : "FALSE") << "\n"; }
    mySet.saveToFile(filename);
}
