/*
 * ScoreBoard.cpp
 *
 *  Created on: May 3, 2019
 *      Author: aleezeh
 */

#include "ScoreBoard.h"

int ScoreBoard::numoflives = 3;
int ScoreBoard::score = 0;
ScoreBoard::ScoreBoard() {
	// TODO Auto-generated constructor stub
}
void ScoreBoard::draw(){
	DrawString(0, 58*14 , "SCORE: ", colors[MISTY_ROSE]);
	DrawString(5*17+2, 58*14 , to_string(score), colors[MISTY_ROSE]);
	
	for(int i = 0; i < numoflives ; i++){
		DrawRectangle(58*17 - i*20, 58*14, 10, 20 , colors[MISTY_ROSE]);
	}
}
void ScoreBoard::incScore(int s){
	if(s>0) score += s;
}
int ScoreBoard::getScore(){
	return score;
}
void ScoreBoard::decNumOfLives(int){
	numoflives -= 1;
}
int ScoreBoard::getNumOfLives(){
	return numoflives;
}
void ScoreBoard::ResetScore(){
	score = 0;
}
void ScoreBoard::ResetLives(){
	numoflives = 1;
}

ScoreBoard::~ScoreBoard() {
	// TODO Auto-generated destructor stub
}

