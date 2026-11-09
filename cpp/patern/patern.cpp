#include <iostream>
#include <string>
#include <vector>
#include "array.h"
using namespace std;

bool isMatch(const string& s, const string& p) {
    int m = s.length(), n = p.length();
    vector<bool> dp(n + 1, false); 
    dp[0] = true;
    
    for (int j = 1; j <= n; ++j) 
        if (p[j - 1] == '*') dp[j] = dp[j - 1];
        
    for (int i = 1; i <= m; ++i) {
        vector<bool> curr(n + 1, false);
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') 
                curr[j] = curr[j - 1] || dp[j];
            else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) 
                curr[j] = dp[j - 1];
        }
        dp = curr;
    }
    return dp[n];
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
