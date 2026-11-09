#include "array.h"
using namespace std;

MyArray::MyArray() : data(new string[1]), count(0), cap(1) {}
MyArray::~MyArray() { delete[] data; }
void MyArray::resize(int newCap) {
    string* temp = new string[newCap];
    for (int i = 0; i < count; ++i) temp[i] = data[i];
    delete[] data; data = temp; cap = newCap;
}
void MyArray::pushBack(const string& v) {
    if (count == cap) resize(cap * 2);
    data[count++] = v;
}
bool MyArray::pushAt(int idx, const string& v) {
    if (idx < 0 || idx > count) return false;
    if (count == cap) resize(cap * 2);
    for (int i = count; i > idx; --i) data[i] = data[i - 1];
    data[idx] = v; count++; return true;
}
bool MyArray::del(int idx) {
    if (idx < 0 || idx >= count) return false;
    for (int i = idx; i < count - 1; ++i) data[i] = data[i + 1];
    count--; return true;
}
bool MyArray::get(int idx, string& out) const {
    if (idx < 0 || idx >= count) return false;
    out = data[idx]; return true;
}
bool MyArray::set(int idx, const string& v) {
    if (idx < 0 || idx >= count) return false;
    data[idx] = v; return true;
}
int MyArray::size() const { return count; }
void MyArray::print() const {
    if (count == 0) { cout << "(empty)\n"; return; }
    for (int i = 0; i < count; ++i) cout << i << ":" << data[i] << "\n";
}
