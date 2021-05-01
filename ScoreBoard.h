/*
 * ScoreBoard.h
 *
 *  Created on: May 3, 2019
 *      Author: aleezeh
 */

#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_
#include"util.h"

class ScoreBoard{
protected:
	static int numoflives;
	static int score;
public:
	int highscore;
	ScoreBoard();
	void draw();
	void incScore(int);
	int getScore();
	void decNumOfLives(int);
	int getNumOfLives();
	void ResetScore();
	void ResetLives();
	virtual ~ScoreBoard();
};

#endif /* SCOREBOARD_H_ */
