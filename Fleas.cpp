/*
 * Fleas.cpp
 *
 *  Created on: May 5, 2019
 *      Author: aleezeh
 */

#include "Fleas.h"
#include "util.h"

Fleas::Fleas() {
	srand(time(NULL));
	direction = 2;
	pos.y = 55;
	pos.x = rand()%60;
}

void Fleas::draw(){
	if(direction == 2){
	DrawRectangle(pos.x*17-2, pos.y*14-8, 10, 20, colors[MISTY_ROSE]);
	DrawLine(pos.x*17 , pos.y*14 +3, pos.x*17 -12, pos.y*14 + 15, 3, colors[MISTY_ROSE]);
	DrawLine(pos.x*17 , pos.y*14 , pos.x*17 - 12, pos.y*14 , 3, colors[MISTY_ROSE]);
	DrawLine(pos.x*17 , pos.y*14 -3, pos.x*17 - 12, pos.y*14 - 15 , 3, colors[MISTY_ROSE]);
	DrawLine(pos.x*17+7 , pos.y*14 +3, pos.x*17 + 19, pos.y*14 + 15, 3, colors[MISTY_ROSE]);
	DrawLine(pos.x*17+7 , pos.y*14 , pos.x*17 + 19, pos.y*14 , 3, colors[MISTY_ROSE]);
	DrawLine(pos.x*17+7 , pos.y*14 -3, pos.x*17 + 19, pos.y*14 - 15, 3, colors[MISTY_ROSE]);
	}
}
void Fleas::setDirection(int d){
	direction = d;
}
int Fleas::getDirection(){
	return direction;
}
void Fleas::move(){
	if(direction == 2) pos.y -= 3;
	if(pos.y == 0 ) direction = 0;
}
int Fleas::getX(){
	return pos.x;
}
int Fleas::getY(){
	return pos.y;
}
bool Fleas::collision(int bx, int by){
	if((bx <= pos.x+2 && bx >= pos.x-2) && (by <= pos.y+2 && by >= pos.y -3)){
		 direction = 0;
		return true;
	}
	return false;
}
Fleas::~Fleas() {
	// TODO Auto-generated destructor stub
}

