#include <iostream>
#include <string>
#include "array.h"
using namespace std;

bool isMatch(const string& s, const string& p) {
    int m = s.length(), n = p.length();
    MyArray dp;
    for (int j = 0; j <= n; ++j) dp.pushBack("0");
    dp.set(0, "1");

    for (int j = 1; j <= n; ++j) {
        string prev;
        dp.get(j - 1, prev);
        if (p[j - 1] == '*' && prev == "1") {
            dp.set(j, "1");
        }
    }

    for (int i = 1; i <= m; ++i) {
        MyArray curr;
        for (int j = 0; j <= n; ++j) curr.pushBack("0");
        for (int j = 1; j <= n; ++j) {
            string dp_j, dp_j_minus_1, curr_j_minus_1;
            dp.get(j, dp_j);
            dp.get(j - 1, dp_j_minus_1);
            curr.get(j - 1, curr_j_minus_1);

            if (p[j - 1] == '*') {
                if (curr_j_minus_1 == "1" || dp_j == "1") {
                    curr.set(j, "1");
                }
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                if (dp_j_minus_1 == "1") {
                    curr.set(j, "1");
                }
            }
        }
        dp = curr;
    }

    string res;
    dp.get(n, res);
    return res == "1";
}

void runPatternMatch() {
    string s, p;
    cout << "Введите строку: "; 
    getline(cin, s);
    cout << "Введите шаблон (с * и ?): "; 
    getline(cin, p);
    
    if (isMatch(s, p)) cout << "Соответствует\n";
    else cout << "Не соответствует\n";
}
