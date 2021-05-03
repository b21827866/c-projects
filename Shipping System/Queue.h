#include <string>
using namespace std;

#ifndef UNTITLED14_QUEUE_H
#define UNTITLED14_QUEUE_H

template<typename T>
class Queue {
public:
    Queue():  _size(0), _lastNode(NULL) {}
    ~Queue() {
        while (!isEmpty())
            dequeue();
    }
    bool isEmpty() const {
        return _size == 0;
    }
    int size() const {
        return _size;
    }
    //Enqueue: Items are added to the back of the queue
    void enqueue(const T& newItem) {
        QueueNode* newNode = new QueueNode(newItem);
        //newNode->item = newItem;
        if (_size > 0) {
            newNode->next = _lastNode->next;
            _lastNode->next = newNode;
            _lastNode = newNode;
        } else {
            newNode->next = newNode;
            _lastNode = newNode;
        }
        ++_size;

    }
    //Dequeue: Items are removed from the front of the queue
    void dequeue() {
        if (isEmpty())
            throw string("Queue is empty on dequeue()");
        else {
            QueueNode* delNode = _lastNode->next;
            //queueFront = delNode->item;
            if (_size > 1)
                _lastNode->next = delNode->next;
            else
                _lastNode = NULL;
            delNode->next = NULL;
            delete delNode;
            delNode = NULL;
            --_size;
        }

    }
    //Get Front: Take a look at the first item
    void getFront(T& queueTop) const {
        if (isEmpty())
            //throw string("Queue is empty");
            cout<<"empty";
        else
            queueTop = _lastNode->next->item;
    }
private:
    struct QueueNode {
        QueueNode(T item){this->item=item, this->next = NULL;};
        T item;
        QueueNode *next;
    };
    int _size;
    /* to avoid the traversal to the last node,
     an additional pointer to the last node is defined*/
    QueueNode *_lastNode;
};
#endif //UNTITLED14_QUEUE_H
