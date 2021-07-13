#pragma once
#ifndef  Resources_H
#define	Resources_H
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Windows.h>
using namespace sf;
using namespace std;

class object {
public:
	Texture* texture;
	RectangleShape* body;
	virtual void update() = 0;
	virtual void start() = 0;
	object() {
		texture = NULL;
		body = NULL;
	}
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
	void updateObjects(RenderWindow*);
};

#endif 
