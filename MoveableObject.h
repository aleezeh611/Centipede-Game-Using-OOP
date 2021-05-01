/*
 * MoveableObject.h
 *
 *  Created on: May 1, 2019
 *      Author: aleezeh
 */

#ifndef MOVEABLEOBJECT_H_
#define MOVEABLEOBJECT_H_
#include"GameObject.h"

class MoveableObject:public GameObject {
protected:
	int direction;
public:
	MoveableObject();
	virtual void move() = 0;
	virtual ~MoveableObject();
};

#endif /* MOVEABLEOBJECT_H_ */
