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
public:
	list();
	void update();
};

#endif 
