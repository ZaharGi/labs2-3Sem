#include <iostream>
#include <string>
#include <vector>
#include "hashset.h"
using namespace std;

string intToRoman(int num) {
    HashSet romanSet;

    romanSet.add("1000", "M");
    romanSet.add("900", "CM");
    romanSet.add("500", "D");
    romanSet.add("400", "CD");
    romanSet.add("100", "C");
    romanSet.add("90", "XC");
    romanSet.add("50", "L");
    romanSet.add("40", "XL");
    romanSet.add("10", "X");
    romanSet.add("9", "IX");
    romanSet.add("5", "V");
    romanSet.add("4", "IV");
    romanSet.add("1", "I");

    vector<int> keys = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string result = "";
    for (int key : keys) {
        string keyStr = to_string(key);
        string sym = romanSet.get(keyStr);
        while (num >= key) {
            result += sym;
            num -= key;
        }
    }
    return result;
}

void runRomanTask() {
    int num;
    cout << "Введите целое число: "; 
    cin >> num;
    cout << "Римская запись: " << intToRoman(num) << "\n";
}
