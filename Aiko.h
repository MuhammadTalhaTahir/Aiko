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
	queue<string> mouseInputLeft;
	queue<string> mouseInputRight;
	queue<string> keyBoardInputW;
	queue<string> keyBoardInputA;
	queue<string> keyBoardInputS;
	queue<string> keyBoardInputD;
	queue<string> keyBoardInputSpace;
	queue<string> keyBoardInputEnter;
public:
	Aiko();
	void Run();
	void insertObject(object*);
	void deleteObject(object*);
	RenderWindow* win();
	bool mouseButtonPressed(string);
	bool keyBoardButtonPressed(string);
	Vector2i getMousePosition();
private:
	void catchEvents();
};
#endif 