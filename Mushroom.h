/*
 * Mushroom.h
 *
 *  Created on: May 2, 2019
 *      Author: aleezeh
 */

#ifndef MUSHROOM_H_
#define MUSHROOM_H_
#include"GameObject.h"
#include "util.h"
#include "Bomb.h"

class Mushroom:public GameObject {
	static int level;
	static int mtotal;
	int hits;
	
public:
	Mushroom();
	virtual void draw();
	virtual void setDirection(int);
	virtual int getDirection();
	virtual void move();
	virtual int getX() ;
	virtual int getY();
	virtual bool collision(int,int );
	int getHits();
	int getTotal();
	void MushroomDelete( int, Mushroom*&);
	void MushroomCreate(Mushroom*& , int, int);
	virtual ~Mushroom();
};

#endif /* MUSHROOM_H_ */
