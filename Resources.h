#pragma once
#ifndef  Resources_H
#define	Resources_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class object {
public:
	virtual void update() = 0;
	virtual void start() = 0;
};

class listNode {
public:
	listNode* next;
	object* data;
	listNode();
};

class list{
private:
	listNode* first;
	int objectCount;
public:
	list();
	void insert(object*);
	void remove(object*);
	int getObjectCount()const;
	void updateObjects();
};

#endif 
