#pragma once
#ifndef queue_H
#define queue_H
#include "Node.h"
using namespace std;
template<class T>
class queue {
private:
    int size;
public:
    node<T>* first, * last;
    queue();
    ~queue();
    void enqueue(T data);
    T dequeue();
    T dequeueLast();
    int getSize();
    void displayQueue()const;
    bool isEmpty();
    T getIndex(int i);
};
#endif
