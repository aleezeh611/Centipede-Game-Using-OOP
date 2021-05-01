/*
 * Bomb.cpp
 *
 *  Created on: May 1, 2019
 *      Author: aleezeh
 */

#include "Bomb.h"

Bomb::Bomb() {
}
void Bomb::setBomb(int x, int y){
	pos.x = x;
	pos.y = y;
}
void Bomb::draw(){
	if(direction == 3 )
	DrawRectangle( pos.x*17+9 , pos.y*14+15 ,7,25,colors[CRIMSON]);
//	cout<<"position of bomb while drawing :  "<<pos.x<<"  "<<pos.y<<endl;
}
void Bomb::move(){
	if(direction == 3 ) pos.y += 3;
	if(pos.y+1 > 56){ direction = -1;}
}
void Bomb::BombDelete(int ind, Bomb*& b , int current){
	int num = current+1;
	Bomb* temp = new Bomb[num];
	for(int i = 0; i < ind ; i++) temp[i] = b[i];
	for (int i = ind, j = ind+1 ; j<num ; j++, i++) temp[i] = b[j];
	delete [] b;
	b = new Bomb[num+1];
	for(int i = 0; i < num ; i++) b[i] = temp[i];
	delete [] temp; 
}
int Bomb::getX(){
	return pos.x;
}
int Bomb::getY(){
	return pos.y;
}
int Bomb::getDirection(){
	return direction;
}
void Bomb::setDirection(int dir){
	direction = dir;
}
Bomb::~Bomb() {
}

