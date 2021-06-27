#pragma once
#ifndef  List_H
#define List_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class object {
public:
	virtual void update() = 0;
	virtual void start() = 0;
};

class Node {
public:
	Node* next;
	object* data;
	Node();
};

class list{
private:
	Node* first;
	int objectCount;
public:
	list();
	void insert(object*);
	void remove(object*);
	int getObjectCount()const;
	void updateObjects();
};

#endif 
