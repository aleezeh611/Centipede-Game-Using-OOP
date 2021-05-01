/*
 * GameObject.h
 *
 *  Created on: May 1, 2019
 *      Author: aleezeh
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include"Position.h"
#include<iostream>
#include<string>
using namespace std;

class GameObject {
protected:
	Position pos;
public:
	GameObject();
	virtual void draw() = 0;
	virtual void setDirection(int) = 0;
	virtual int getDirection() = 0;
	virtual void move() = 0;
	virtual void setBomb(int, int) ;
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual bool collision(int, int);
	virtual ~GameObject();
};

#endif /* GAMEOBJECT_H_ */
