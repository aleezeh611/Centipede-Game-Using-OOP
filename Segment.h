/*
 * Segment.h
 *
 *  Created on: May 4, 2019
 *      Author: aleezeh
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_
#include"LazySeg.h"
#include"MoveableObject.h"
#include"Mushroom.h"
#include"ScoreBoard.h"

class Segment: public MoveableObject {
protected:
	int length;
	LazySeg* seg;
public:
	Segment();
	Segment(int);
	void setSegment(int);
	void draw();
	void move();
	void setDirection(int);
	int getDirection();
	virtual int getX();
	virtual int getY();
	void collidewithmushrooms(int, int);
	void CreateCentipede(int, int, int, int , int , Segment*&);
	bool collision(int& ,  int, int,  Mushroom*&, ScoreBoard&);
	virtual ~Segment();
};

#endif /* SEGMENT_H_ */
