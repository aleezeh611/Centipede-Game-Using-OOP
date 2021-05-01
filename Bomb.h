/*
 * Bomb.h
 *
 *  Created on: May 1, 2019
 *      Author: aleezeh
 */

#ifndef BOMB_H_
#define BOMB_H_
#include"MoveableObject.h"
#include "util.h"

class Bomb:public MoveableObject {
public:
	Bomb();
	void move();
	void draw();
	int getX();
	int getY();
	int getDirection();
	void setDirection(int);
	void setBomb(int, int);
	void BombDelete(int, Bomb*&, int);
	virtual ~Bomb();
};

#endif /* BOMB_H_ */
