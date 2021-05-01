/*
 * AllVariables.h
 *
 *  Created on: May 4, 2019
 *      Author: aleezeh
 */

#ifndef ALLVARIABLES_H_
#define ALLVARIABLES_H_
#include "util.h"
#include "Player.h"
#include "Bomb.h"
#include "Mushroom.h"
#include "ScoreBoard.h"
#include "Segment.h"
#include "Fleas.h"

class AllVariables {
	public:
		int GameOver = 1;
		GameObject* player;
		Bomb* bomb;
		int i = -1;
		Mushroom* mushrooms;
		ScoreBoard Stats;
		Segment* centipede;
		int cen = 0;
		GameObject* flea;
		int fleacheck = 1;
};

#endif /* ALLVARIABLES_H_ */
