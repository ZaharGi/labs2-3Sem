#ifndef STACK_H
#define STACK_H

struct SNode {
    char value;
    SNode* next;
    SNode(char v) : value(v), next(nullptr) {}
};

class Stack {
private:
    SNode* head;
public:
    Stack() : head(nullptr) {}
    ~Stack() {
        while (head) { SNode* t = head; head = head->next; delete t; }
    }
    void push(char v) {
        SNode* n = new SNode(v);
        n->next = head;
        head = n;
    }
    char pop() {
        if (!head) return '\0';
        SNode* t = head;
        char val = t->value;
        head = head->next;
        delete t;
        return val;
    }
    char top() const { return head ? head->value : '\0'; }
    bool empty() const { return head == nullptr; }
};
#endif
