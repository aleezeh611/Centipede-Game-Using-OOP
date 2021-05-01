/*
 * Segment.cpp
 *
 *  Created on: May 4, 2019
 *      Author: aleezeh
 */

#include "Segment.h"

Segment::Segment(){
	srand(time(NULL));
	length = 10;
	if( length > 0 ){
		seg = new LazySeg[length];
		seg[0].setX( rand()%60 );
		seg[0].setY(55) ;
		direction = rand()%2 +1;

		for(int b = 1 ; b <= length ; b++){
			if(direction == 1) seg[b].setX( seg[0].getX() - b);
			else if(direction ==2 ) seg[b].setX(seg[0].getX() + b);
			seg[b].setY( seg[0].getY());
		}
	}
}
void Segment::setSegment(int l){
	srand(time(NULL));
	length = l;

	if( length > 0 ){
		delete [] seg;
		seg = new LazySeg[length];
		seg[0].setX( rand()%60 );
		seg[0].setY(55) ;
		direction = rand()%2 +1;

		for(int b = 1 ; b <= length ; b++){
			if(direction == 1) seg[b].setX( seg[0].getX() - b);
			else if(direction ==2 ) seg[b].setX(seg[0].getX() + b);
			seg[b].setY( seg[0].getY());
		}
	}
}
void Segment::move(){
	int tempx1, tempx2, tempy1, tempy2;
	int gap; // to overcome gaps formed due to steps of 2
	
	tempx1 = seg[0].getX();
	tempy1 = seg[0].getY();

	if(direction == 1){
		seg[0].setX(seg[0].getX() + 2);
		gap = 1;
	}
	if (direction == 2){
		seg[0].setX(seg[0].getX()- 2);
		gap = -1;
	}	
	
	for(int b = 1 ; b < length ; b++){
		tempx2 = seg[b].getX() ;
		tempy2 = seg[b].getY();
		seg[b].setX(tempx1 + gap);
		seg[b].setY(tempy1);
		tempx1 = tempx2;
		tempy1 = tempy2;
	}
	if(seg[0].getX() <= 0){
		seg[0].setY(seg[0].getY()-1);
		direction = 1;
	}
	if(seg[0].getX() >= 60){
		seg[0].setY(seg[0].getY()-1);
		direction = 2;
	}
}
void Segment::draw(){
	if(length > 0){
		for(int b = 0 ; b < length ; b++){
			seg[b].draw();
		}
	}
}
void Segment::setDirection(int d){
	if(d == 1 || d==2) direction = d;
}
int Segment::getDirection(){
	return direction;
}
int Segment::getX(){
	return seg[0].getX();
}
int Segment::getY(){
	return seg[0].getY();
}
void Segment::collidewithmushrooms(int mx , int my){
	if(direction == 1){
		if((seg[0].getX()+3 >= mx && seg[0].getX()-1 <= mx) && seg[0].getY() == my){
			seg[0].setY(seg[0].getY()-1);
			direction = 2;
			//move();
		}
	}
	else if(direction == 2){
		if((seg[0].getX()-3 <= mx && seg[0].getX()+1 >= mx)&& seg[0].getY() == my){
			seg[0].setY(seg[0].getY()-1);
			direction = 1;
			//move();
		}
	}
}
void Segment::CreateCentipede(int ind, int num, int l, int px, int py, Segment*& s){
	int d;
	if(s[ind].direction==1) d = 2;
	if(s[ind].direction==2) d = 1;

	Segment* temp = new Segment[num];

	for(int i = 0; i< num ; i++) temp[i] = s[i];

	delete [] s;
	s = new Segment[num+1];
	for(int i = 0; i < num ; i++) s[i] = temp[i];

	s[num].setSegment(5);

	s[num].seg[0].setX(px);
	for(int i = 0; i < l ; i++) s[num].seg[i].setY(py);
	s[num].direction = d;

	delete [] temp;

}
bool Segment::collision( int& game, int bx, int by, Mushroom*& m, ScoreBoard& sc){
	for(int i = 0; i < length ; i++){
		if((bx >= seg[i].getX()-3 && bx<= seg[i].getX()+3) && (by >= seg[i].getY()-2 && by <= seg[i].getY()+1)){
			m->MushroomCreate(m, bx, by);
			if(i == 0) sc.incScore(100);
			else sc.incScore(10);
			LazySeg* temp = new LazySeg[length-1];
			for(int i = 0; i < length - 1; i++) temp[i] = seg[i];
			
			length -= 1;
			if(length > 0 ){
				delete [] seg;
				seg = new LazySeg[length];
				for(int i = 0; i < length ; i++) seg[i] = temp[i]; 
			}
			else  game = 3;
			delete [] temp;
			return true;
		}
	}
	return false;
}

Segment::~Segment() {
	// TODO Auto-generated destructor stub
}














