/*
 * LazySeg.cpp
 *
 *  Created on: May 4, 2019
 *      Author: aleezeh
 */

#include "LazySeg.h"
#include"util.h"
LazySeg::LazySeg() {
	// TODO Auto-generated constructor stub
}
void LazySeg::draw(){
	DrawCircle(pos.x*17 , pos.y*14 ,10 ,colors[DARK_OLIVE_GREEN]);
	DrawCircle(pos.x*17 , pos.y*14 ,7 ,colors[SPRING_GREEN]);
}
void LazySeg::setDirection(int d){	}
int LazySeg::getDirection(){ }
void LazySeg::move(){ }
int LazySeg::getX() {
	return pos.x;
}
int LazySeg::getY() {
	return pos.y;
}
void LazySeg::setX(int sx){
	if(sx >= 0 && sx <= 60) pos.x  = sx;
}
void LazySeg::setY(int sy){
	if(sy >= 0 && sy<=55) pos.y = sy;
}
LazySeg::~LazySeg() {
	// TODO Auto-generated destructor stub
}

