#pragma once
#ifndef  List_H
#define List_H
#include "Aiko.h"


class node {
public:
	node* next;
	object* data;
	node();
};

class list
{
private:
	node* first;
	int objectCount;
public:
	list();
	void insert(object*);
	void remove(object*);
	int getObjectCount()const;

	void update();
};

#endif 
