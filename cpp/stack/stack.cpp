#include <iostream>
#include <string>
#include <cctype>
#include "stack.h"
using namespace std;

int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string& expr) {
    Stack opStack; 
    string result;
    for (char c : expr) {
        if (isspace(c)) continue;
        if (isalnum(c)) result += c;
        else if (c == '(') opStack.push(c);
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') result += opStack.pop();
            if (!opStack.empty()) opStack.pop();
        } else {
            while (!opStack.empty() && getPriority(opStack.top()) >= getPriority(c)) result += opStack.pop();
            opStack.push(c);
        }
    }
    while (!opStack.empty()) result += opStack.pop();
    return result;
}
