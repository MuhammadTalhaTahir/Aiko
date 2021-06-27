#include <iostream>
#include "node.h"
using namespace std;

template<class T>
node<T>::node() {
    if (next != NULL) next = NULL;
    if (pre != NULL) pre = NULL;
    isDel=false;
}
template<class T>
node<T>::~node() {
    if (next != NULL) next = NULL;
    if (pre != NULL) pre = NULL;
}
template<class T>
void node<T>::setData(T data) {
    this->data = data;
}
template<class T>
T node<T>::getData() {
    return data;
}