#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include "stack.h"
#include "hashset.h"
#include "array.h"
#include "tree.h"
#include "lru.h"

using namespace std;

string infixToPostfix(const string& expr);
void executeQuery(const string& filename, const string& query);
void runSetOperations();
void runPatternMatch();
void runTreeTask();
void runRomanTask();

enum class MenuOption {
    Exit = 0,
    StackInfixToPostfix = 1,
    SetCLI = 2,
    SetOperations = 3,
    ArrayPatternMatch = 4,
    TreeAVLCheck = 5,
    RomanConversion = 6,
    LRUCache = 7
};

void printMenu() {
    cout << "1. Стек\n";
    cout << "2. Множество\n";
    cout << "3. Множество\n";
    cout << "4. Массив\n";
    cout << "5. Дерево\n";
    cout << "6. Хеш-таблица\n";
    cout << "7. LRU-кэш\n";
    cout << "0. Выход\n";
    cout << "Выберите задание: ";
}

int main(int argc, char* argv[]) {
    string filename = "data.txt";
    string query = "";

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "--file" && i + 1 < argc) filename = argv[++i];
        else if (arg == "--query" && i + 1 < argc) query = argv[++i];
    }

    if (!query.empty()) {
        executeQuery(filename, query);
        return 0;
    }

    int inputChoice;
    while (true) {
        printMenu();
        if (!(cin >> inputChoice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        MenuOption choice = static_cast<MenuOption>(inputChoice);
        cin.ignore(); 

        switch (choice) {
            case MenuOption::Exit:
                return 0;

            case MenuOption::StackInfixToPostfix: {
                string expr;
                cout << "Введите инфиксное выражение: ";
                getline(cin, expr);
                cout << "Постфиксная запись: " << infixToPostfix(expr) << "\n";
                break;
            }

            case MenuOption::SetCLI: {
                string cmd, val;
                cout << "Введите запрос (например, SETADD A): ";
                cin >> cmd >> val;
                executeQuery("data.txt", cmd + " " + val);
                break;
            }

            case MenuOption::SetOperations:
                runSetOperations();
                break;

            case MenuOption::ArrayPatternMatch:
                runPatternMatch();
                break;

            case MenuOption::TreeAVLCheck:
                runTreeTask();
                break;

            case MenuOption::RomanConversion:
                runRomanTask();
                break;

            case MenuOption::LRUCache:
                runLRUTask();
                break;

            default:
                cout << "Неверный пункт меню.\n";
                break;
        }
    }
    return 0;
}
