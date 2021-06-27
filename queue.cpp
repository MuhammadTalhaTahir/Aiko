#include <iostream>
#include"queue.h"
using namespace std;

template<class T>
queue<T>::queue() {
    first = last = NULL; 
    size = 0;
}
template<class T>
void queue<T>::enqueue(T data) {
    if (first == NULL) {
        first = new node<T>;
        first->setData(data);
        last = first;
        size++;
    }
    else {
        last->next = new node<T>;
        last->next->pre = last;
        last = last->next;
        last->setData(data);
        size++;
    }
}
template<class T>
T queue<T>::dequeue() {
    if (first != NULL) {
        T temp = first->getData();
        node<T>* tem = first;
        first = first->next;
        if (first != NULL && first->pre != NULL)first->pre = NULL;
        if (tem != NULL) delete tem;
        size--;
        return temp;
    }
    else return -99999;
}
template<class T>
bool queue<T>::isEmpty() {
    if (first == NULL)return true;
    else return false;
}
template<class T>
queue<T>::~queue() {
    if (first != NULL) {
        node<T>* temp;
        while (first != NULL) {
            temp = first;
            first = first->next;
            if (temp != NULL)delete temp;
        }
        if (first != NULL)first = NULL;
        if (last != NULL)last = NULL;

    }
}
template<class T>
T queue<T>::dequeueLast() {
    if (first == NULL) return -99999;
    if (last == first) {
        T ret = first->getData();
        if (first != NULL)delete first;
        if (first != NULL) first = NULL;
        if (last != NULL) last = NULL;
        size--;
        return ret;
    }
    else {
        T ret = last->getData();
        node<T>* temp = last;
        last = last->pre;
        if (last->next != NULL)last->next = NULL;
        if (temp != NULL)delete temp;
        size--;
        return ret;
    }
}
template<class T>
void queue<T>::displayQueue()const {
    node<T>* temp = first;
    while (temp != NULL) {
        cout << "#" << endl;
        temp = temp->next;
    }
}
template<class T>
int queue<T>::getSize() {
    return size;
}
template<class T>
T queue<T>::getIndex(int i) {
    if (i < this->getSize()) {
        node<T>* temp = first;
        int count = 0;
        while (count != i && temp != NULL) {
            temp = temp->next;
            count++;
        }
        return temp->getData();
    }
}
