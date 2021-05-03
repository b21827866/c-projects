#include <string>

using namespace std;

#ifndef UNTITLED14_STACK_H
#define UNTITLED14_STACK_H

template <typename T>
class Stack {
private:
    struct ListNode {
        //ListNode(T item, ListNode* next){this->item=item; this->next=next;};
        ListNode(T item){this->item=item, this->next = NULL;};
        T item;
        ListNode* next;
    };
    ListNode* _head;
    int _size;
public:
    Stack() : _size(0), _head(NULL) {}
    ~Stack() {
        while (!isEmpty())
        pop();
    }
    bool isEmpty() const {
        return _size == 0;
    }
    int size() const {
        return _size;
    }
    void push(const T& newItem) {
        ListNode* newPtr = new ListNode(newItem);

        //newPtr->item = newItem;
        newPtr->next = _head;
        _head = newPtr;
        _size++;
    }
    void getTop(T& stackTop) const {
        if (isEmpty())
            //throw string("Stack is empty on top()");
            cout << "Stack is empty on top()";

        else {
            stackTop = _head->item;
        }
    }
    void pop() {
        if (isEmpty())
            //throw string("Stack is empty on pop()");
            cout << "Stack is empty on top()" << endl;
        else {
            ListNode* cur;
            cur = _head;
            _head = _head->next;
            delete cur;
            cur = NULL;
            _size--;

        }
    }

};

#endif //UNTITLED14_STACK_H
