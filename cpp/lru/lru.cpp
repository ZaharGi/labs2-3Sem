#include "lru.h"
#include <iostream>
#include <list>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> items;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        items.splice(items.begin(), items, cache[key]);
        return cache[key]->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->second = value;
            items.splice(items.begin(), items, cache[key]);
            return;
        }
        if (items.size() == capacity) {
            cache.erase(items.back().first);
            items.pop_back();
        }
        items.push_front({key, value});
        cache[key] = items.begin();
    }
};

void runLRUTask() {
    int cap, q;
    cout << "Введите емкость кэша: ";
    cin >> cap;
    cout << "Введите количество запросов: ";
    cin >> q;
    cin.ignore();

    LRUCache lru(cap);
    cout << "Введите запросы (например: SET 1 2 GET 1):\n";

    string line;
    getline(cin, line);
    istringstream iss(line);
    string cmd;

    while (iss >> cmd) {
        if (cmd == "SET") {
            int k, v;
            iss >> k >> v;
            lru.put(k, v);
        } else if (cmd == "GET") {
            int k;
            iss >> k;
            cout << lru.get(k) << " ";
        }
    }
    cout << "\n";
}
