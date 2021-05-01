/*
 * LazySeg.h
 *
 *  Created on: May 4, 2019
 *      Author: aleezeh
 */

#ifndef LAZYSEG_H_
#define LAZYSEG_H_
#include"MoveableObject.h"

class LazySeg: public MoveableObject{//3 members: pos.x, pos.y and direction
public:
	LazySeg();
	void draw();
	virtual void setDirection(int);
	virtual int getDirection();
	virtual void move();
	virtual int getX();
	virtual int getY();
	void setX(int);
	void setY(int);
	virtual ~LazySeg();
};

#endif /* LAZYSEG_H_ */
