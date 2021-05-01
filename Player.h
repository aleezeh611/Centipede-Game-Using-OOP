/*
 * Player.h
 *
 *  Created on: May 1, 2019
 *      Author: aleezeh
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include"MoveableObject.h"
#include "util.h"

class Player:public MoveableObject {
public:
	Player();
	void draw();
	void move();
	int getDirection();
	void setDirection(int);
	int getX();
	int getY();
	bool collision(int , int);
	virtual ~Player();
};

#endif /* PLAYER_H_ */
