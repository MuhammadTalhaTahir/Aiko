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
	const int windowX;
	const int windowY;
	/*Only for Intro*/
	RectangleShape* intro;
	Texture* introTexture;
	SoundBuffer* buffer;
	Sound* sound;
	/*Only for Intro*/
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
	bool isCursorOverObject(RectangleShape*);
private:
	void catchEvents();
	void loadIntro();
};
#endif 