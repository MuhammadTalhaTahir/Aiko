#pragma once
#ifndef Aiko_H
#define Aiko_H
#include "List.h"

class Aiko{
private:
	list aikoObjects;
	RenderWindow* window;
	Event* events;
public:
	Aiko();
	void Run();
	void insertObject(object*);
	void deleteObject(object*);
	RenderWindow* win();
private:
	void catchEvents();
};
#endif 