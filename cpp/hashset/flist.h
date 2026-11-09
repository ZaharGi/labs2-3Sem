#ifndef FLIST_H
#define FLIST_H
#include <string>

struct FNode {
    std::string key;
    std::string value;
    FNode* next;
    FNode(const std::string& k, const std::string& v) : key(k), value(v), next(nullptr) {}
};

class ForwardList {
    friend class HashSet;
private:
    FNode* head;
public:
    ForwardList() : head(nullptr) {}
    ~ForwardList() { clear(); }
    void clear() {
        while (head) { FNode* t = head; head = head->next; delete t; }
    }
    void pushTail(const std::string& k, const std::string& v) {
        FNode* n = new FNode(k, v);
        if (!head) { head = n; return; }
        FNode* c = head;
        while (c->next) c = c->next;
        c->next = n;
    }
    bool search(const std::string& k) const {
        for (FNode* c = head; c; c = c->next)
            if (c->key == k) return true;
        return false;
    }
    std::string get(const std::string& k) const {
        for (FNode* c = head; c; c = c->next)
            if (c->key == k) return c->value;
        return "";
    }
};
#endif
