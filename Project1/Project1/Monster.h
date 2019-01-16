#pragma once
// Monster is inherited from Common_
#include "common.h"
#include "Hero.h"

class Hero;

class Monster:
	public Common_
{
public:
	Monster(int h, int a, int d);

	/*Prepare the defence*/
	int prepare_defence();
	/*After the defence*/
	int relax_defence();

	/*prepare the fight*/
	int prepare_fight();
	/*after the fight*/
	int relax_fight();

	/*Fight against the hero*/
	int fight(Hero *h);
	
	~Monster();
};

