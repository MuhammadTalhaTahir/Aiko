#pragma once
#include<iostream>
using namespace std;
template<class T>
class Node
{
	T data;
public:
	Node<T>* next;
	Node();
	Node(T z);
	T getdata();
};
