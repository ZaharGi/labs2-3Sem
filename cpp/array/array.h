#ifndef ARRAY_H
#define ARRAY_H
#include <string>
#include <iostream>

class MyArray {
private:
    std::string* data;
    int count;
    int cap;
    void resize(int newCap);
public:
    MyArray();
    ~MyArray();
    void pushBack(const std::string& v);
    bool pushAt(int idx, const std::string& v);
    bool del(int idx);
    bool get(int idx, std::string& out) const;
    bool set(int idx, const std::string& v);
    int size() const;
    void print() const;
};
#endif
