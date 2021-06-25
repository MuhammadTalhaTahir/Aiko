#pragma once
#ifndef Aiko_H
#define Aiko_H
#include <iostream>
using namespace std;


class Aiko
{
};


class object {
private:
	Aiko* engine;
public:
	virtual void update() = 0;
};
#endif 