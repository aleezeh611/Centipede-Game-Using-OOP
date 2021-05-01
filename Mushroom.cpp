/*
 * Mushroom.cpp
 *
 *  Created on: May 2, 2019
 *      Author: aleezeh
 */

#include "Mushroom.h"
#include<cstdlib>
#include<ctime>

int Mushroom :: level = 1;
int Mushroom :: mtotal = 25;

Mushroom::Mushroom() {

	hits = 0;
	pos.y = (rand()%50) +1 ;
	pos.x = rand() % 50 + 5;
}
void Mushroom::draw(){
	if(hits == 0){
	DrawRectangle(pos.x*17-5, pos.y*14-16, 10, 9, colors[BLUE]);
	DrawCircle(pos.x*17, pos.y*14 ,10 ,colors[BLUE]);
	DrawCircle(pos.x*17 , pos.y*14 ,6 ,colors[PURPLE]);
	}
	if(hits == 1){
	DrawRectangle(pos.x*17-3, pos.y*14-15, 6, 10, colors[PURPLE]);
	DrawCircle(pos.x*17, pos.y*14 ,7 ,colors[PURPLE]);
	DrawCircle(pos.x*17 , pos.y*14 ,4 ,colors[BLUE]);
	}
}
void Mushroom::setDirection(int){
	//do nothing
}
int Mushroom::getDirection(){
	//do nothing
}
void Mushroom::move(){
	//mushrooms cannot move
}
int Mushroom::getX(){
	return pos.x;
}
int Mushroom::getY(){
	return pos.y;
}
int Mushroom::getHits(){
	return hits;
}
bool Mushroom::collision(int bx, int by){
	if( ( bx >= pos.x-1 && bx <= pos.x-0.5 ) && (by <= pos.y+3 && by>= pos.y-3) ){
	hits++;
	return true;
	}
	else return false;
}
int Mushroom::getTotal(){
	return mtotal;
}
void Mushroom::MushroomDelete(int ind, Mushroom*& m){
	int num = m[0].getTotal();
	Mushroom* temp = new Mushroom[num-1];
	for(int i = 0; i < ind ; i++) temp[i] = m[i];
	for (int i = ind, j = ind+1 ; j<num ; j++, i++) temp[i] = m[j];
	delete [] m;
	num = --temp[0].mtotal;
	m = new Mushroom[num];
	for(int i = 0; i < num ; i++) m[i] = temp[i];
	delete [] temp;
}
void Mushroom::MushroomCreate(Mushroom*& m , int nx, int ny){
	int num = m->getTotal();

	Mushroom* temp = new Mushroom[num];
	for(int i = 0; i < num ; i++) temp[i] = m[i];
	delete [] m;

	m = new Mushroom[num+1];
	for(int i = 0; i < num ; i++) m[i] = temp[i];
	m[num].pos.x = nx;
	m[num].pos.y = ny;
	m[num].hits = 0;
	
	num = ++temp->mtotal;
	m->mtotal = num;

	delete [] temp;
}
Mushroom::~Mushroom() {
	// TODO Auto-generated destructor stub
}

