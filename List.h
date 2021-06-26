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
};

class node {
public:
	node* next;
	object* data;
	node();
};

class list{
private:
	node* first;
	int objectCount;
public:
	list();
	void insert(object*);
	void remove(object*);
	int getObjectCount()const;
	void updateObjects();
};

#endif 
