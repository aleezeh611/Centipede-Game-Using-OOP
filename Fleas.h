/*
 * Fleas.h
 *
 *  Created on: May 5, 2019
 *      Author: aleezeh
 */

#ifndef FLEAS_H_
#define FLEAS_H_
#include"MoveableObject.h"
//#include"Mushroom.h"

class Fleas:public MoveableObject {
public:
	Fleas();
	virtual void draw();
	virtual void setDirection(int);
	virtual int getDirection();
	virtual void move();
	virtual int getX();
	virtual int getY() ;
	bool collision(int, int);
	virtual ~Fleas();
};

#endif /* FLEAS_H_ */
