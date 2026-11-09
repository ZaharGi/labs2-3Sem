#include "hashset.h"
#include <iostream>
using namespace std;

void runSetOperations() {
    HashSet setA, setB;
    string val;
    
    cout << "Введите элементы первого множества (end для конца): ";
    while (cin >> val && val != "end") setA.add(val);
    
    cout << "Введите элементы второго множества (end для конца): ";
    while (cin >> val && val != "end") setB.add(val);

    cout << "Множество A: { ";
    setA.forEach([](const string& v) { cout << v << " "; });
    cout << "}\n";

    cout << "Множество B: { ";
    setB.forEach([](const string& v) { cout << v << " "; });
    cout << "}\n";

    HashSet uni;
    setA.forEach([&](const string& v) { uni.add(v); });
    setB.forEach([&](const string& v) { uni.add(v); });
    cout << "Объединение (A U B): { ";
    uni.forEach([](const string& v) { cout << v << " "; });
    cout << "}\n";

    HashSet inter;
    setA.forEach([&](const string& v) { if (setB.at(v)) inter.add(v); });
    cout << "Пересечение (A ∩ B): { ";
    inter.forEach([](const string& v) { cout << v << " "; });
    cout << "}\n";

    HashSet diff;
    setA.forEach([&](const string& v) { if (!setB.at(v)) diff.add(v); });
    cout << "Разность (A \\ B): { ";
    diff.forEach([](const string& v) { cout << v << " "; });
    cout << "}\n";
}
