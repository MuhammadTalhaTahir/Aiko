#pragma once
#ifndef Aiko_H
#define Aiko_H
#include "Resources.h"
#include "queue.h"
#include "queue.cpp"
#include "Node.cpp"

class Aiko{
private:
	list aikoObjects;
	RenderWindow* window;
	Event* events;
	char input;
public:
	Aiko();
	void Run();
	void insertObject(object*);
	void deleteObject(object*);
	RenderWindow* win();
	bool isMouseButtonPressed();
private:
	void catchEvents();
};
#endif 