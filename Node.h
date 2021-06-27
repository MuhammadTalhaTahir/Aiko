#pragma once
#ifndef Node_H
#define Node_H
using namespace std;

template<class T>
class node {
private:
    T data;
public:
    bool isDel;
    node<T>* next;
    node<T>* pre;
    node();
    ~node();
    void setData(T data);
    T getData();
};

#endif
