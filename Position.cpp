/*
 * Position.cpp
 *
 *  Created on: May 1, 2019
 *      Author: aleezeh
 */

#include "Position.h"

Position::Position() {
	x = y = 0;
}

Position:: Position(int tempx,int tempy){
	if(tempx >= 0 && tempx<= 60 ) x = tempx;
	if(tempy >= 0 && tempy<= 60 )	y = tempy;
}
Position::~Position() {
	// TODO Auto-generated destructor stub
}

