/*
 * Player.cpp
 *
 *  Created on: May 1, 2019
 *      Author: aleezeh
 */

#include "Player.h"

Player::Player() {
	pos.x = pos.y = 0;
}

void Player::draw(){
	DrawRectangle(pos.x*17 +  5 , pos.y*14+2, 16, 24 ,colors[CRIMSON]);
	DrawRoundRect( float(pos.x*17-2) , float(pos.y*14+2), 30.0 ,14.0 ,colors[CRIMSON], 2.0);
	DrawRectangle(pos.x*17 +  8 , pos.y*14+6, 10, 17 ,colors[CORAL]);
	DrawRoundRect( float(pos.x*17+1) , float(pos.y*14+5), 23.0 ,10.0 ,colors[CORAL], 2.0);
}

void Player::move(){
	if(direction == 1) {
		pos.x += 1;
		if(pos.x*17 > 60*17) pos.x = 0;
		if(pos.x*17 < 0)  pos.x = 60;
	}
	if(direction == 2){
		pos.x -= 1;
		if(pos.x*17 > 60*17) pos.x = 0;
		if(pos.x*17 < 0)  pos.x = 60;
	}
	if(direction == 3) {
		if(pos.y*14 < 5*14 && pos.y*14 >= 0) pos.y += 1;
	}
	if(direction == 4) {
		if(pos.y*14 <= 5*14 && pos.y*14 > 0) pos.y -= 1;
	}
}

int Player::getDirection(){
	return direction;
}

void Player::setDirection(int dir){
	if(dir == 1 || dir == 2 || dir == 3 || dir == 4)
	direction = dir;
}

int Player::getX(){
	return pos.x;
}

int Player::getY(){
	return pos.y;
}
bool Player::collision(int px, int py){
	if((px >= pos.x-2 && px <= pos.x+2) && (py >= pos.y-2 && py <= pos.y+2)) return true;
	return false;
}
Player::~Player(){ }

