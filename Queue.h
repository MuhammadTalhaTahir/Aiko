#pragma once
#include"Node.h"
#include"Node.cpp"
template<typename T>
class Queue
{
	Node<T>* head;
public:
	Queue();
	void enQueue(T data);
	T deQueue();
	bool isEmpty();
	~Queue();
};

