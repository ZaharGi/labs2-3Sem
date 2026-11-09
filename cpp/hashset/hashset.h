#ifndef HASHSET_H
#define HASHSET_H
#include <string>
#include <fstream>
#include <cstdint>
#include "flist.h"

class HashSet {
private:
    struct Bucket { ForwardList chain; };
    Bucket* table;
    int cap;
    int count;

    uint64_t hash(const std::string& s) const {
        uint64_t h = 14695981039346656037ULL;
        for (char c : s) { h ^= static_cast<uint64_t>(c); h *= 1099511628211ULL; }
        return h;
    }
    void rehash() {
        int oldCap = cap;
        Bucket* old = table;
        cap *= 2;
        table = new Bucket[cap];
        count = 0;
        for (int i = 0; i < oldCap; ++i)
            for (FNode* n = old[i].chain.head; n; n = n->next)
                add(n->key, n->value); // Перекладываем ключ-значение
        delete[] old;
    }
public:
    explicit HashSet(int initialCap = 16) : cap(initialCap), count(0) {
        if (cap < 2) cap = 2;
        table = new Bucket[cap];
    }
    ~HashSet() { delete[] table; }
    HashSet(const HashSet&) = delete;
    HashSet& operator=(const HashSet&) = delete;

    // Добавление ключ - значение
    void add(const std::string& k, const std::string& v = "") {
        int idx = static_cast<int>(hash(k) & (cap - 1));
        if (table[idx].chain.search(k)) return; // Ключ уже есть
        table[idx].chain.pushTail(k, v);
        count++;
        if (count * 4 > cap * 3) rehash();
    }

    // Поиск
    bool at(const std::string& k) const {
        int idx = static_cast<int>(hash(k) & (cap - 1));
        return table[idx].chain.search(k);
    }

    // Получение значения по ключу
    std::string get(const std::string& k) const {
        int idx = static_cast<int>(hash(k) & (cap - 1));
        return table[idx].chain.get(k);
    }

    // Удаление
    bool del(const std::string& k) {
        int idx = static_cast<int>(hash(k) & (cap - 1));
        FNode* curr = table[idx].chain.head;
        FNode* prev = nullptr;
        while (curr) {
            if (curr->key == k) {
                if (prev) prev->next = curr->next;
                else table[idx].chain.head = curr->next;
                delete curr;
                count--;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }
    
    template<typename Func>
    void forEach(Func f) const {
        for (int i = 0; i < cap; ++i)
            for (FNode* n = table[i].chain.head; n; n = n->next)
                f(n->key, n->value);
    }
};
#endif
