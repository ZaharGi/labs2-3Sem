#include <iostream>
#include "tree.h"
using namespace std;

void runTreeTask() {
    int n, val;
    cout << "Сколько чисел в последовательности? "; 
    cin >> n;
    
    cout << "Введите числа (через пробел):\n";
    Tree tree;
    for (int i = 0; i < n; ++i) { 
        cin >> val; 
        tree.insert(val); 
    }
    
    cout << "Сбалансировано (AVl): " << (isAVL(tree.getRoot()) ? "YES" : "NO") << "\n";
}
