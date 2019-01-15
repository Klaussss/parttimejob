#pragma once
#include "common.h"
#include "Hero.h"

class Hero;

class Monster:
	public Common_
{
public:
	Monster(int h, int a, int d);

	int prepare_defence();
	int relax_defence();

	int prepare_fight();
	int relax_fight();

	int fight(Hero *h);
	
	~Monster();
};

