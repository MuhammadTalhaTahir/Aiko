#pragma once
#ifndef Aiko_H
#define Aiko_H
#include <iostream>
//#include <SFML/Graphics.hpp>
//using namespace sf;
using namespace std;
#include "List.h"
class object {
private:
	Aiko* engine;
public:
	virtual void update() = 0;
};

class Aiko
{
	list a;
};

#endif 