#include <iostream>
#include "hashset.h"
using namespace std;

HashSet setUnion(const HashSet& a, const HashSet& b) {
    HashSet result;
    a.forEach([&](const string& v, const string&) { result.add(v); });
    b.forEach([&](const string& v, const string&) { result.add(v); });
    return result;
}

HashSet setIntersection(const HashSet& a, const HashSet& b) {
    HashSet result;
    a.forEach([&](const string& v, const string&) { 
        if (b.at(v)) result.add(v); 
    });
    return result;
}

HashSet setDifference(const HashSet& a, const HashSet& b) {
    HashSet result;
    a.forEach([&](const string& v, const string&) { 
        if (!b.at(v)) result.add(v); 
    });
    return result;
}

void runSetOperations() {
    HashSet setA, setB;
    string val;
    
    cout << "Элементы 1-го мн-ва (end для конца): ";
    while (cin >> val && val != "end") setA.add(val);
    cout << "Элементы 2-го мн-ва (end для конца): ";
    while (cin >> val && val != "end") setB.add(val);

    cout << "Множество A: { "; setA.forEach([](const string& v, const string&){ cout << v << " "; }); cout << "}\n";
    cout << "Множество B: { "; setB.forEach([](const string& v, const string&){ cout << v << " "; }); cout << "}\n";

    HashSet uni = setUnion(setA, setB);
    cout << "Объединение: { "; uni.forEach([](const string& v, const string&){ cout << v << " "; }); cout << "}\n";

    HashSet inter = setIntersection(setA, setB);
    cout << "Пересечение: { "; inter.forEach([](const string& v, const string&){ cout << v << " "; }); cout << "}\n";

    HashSet diff = setDifference(setA, setB);
    cout << "Разность: { "; diff.forEach([](const string& v, const string&){ cout << v << " "; }); cout << "}\n";
}
