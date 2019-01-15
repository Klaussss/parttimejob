#pragma once
#include "common.h"
#include "Monster.h"

#ifndef __HERO__
#define __HERO__

class Monster;
class Hero :
	public Common_
{
private:
	int Special;
	int Coins = 0;
	Hero(int h, int a, int d, int s);
	static Hero *instance;
public:
	static Hero* getHero(int h, int a, int d, int s);

	int prepare_defence();
	int relax_defence();

	int prepare_fight();
	int relax_fight();

	int fight(Monster *m);

	int specialAttack();

	int reward();

	void healthStat();

	int limit();

	int setname(string str);

	int saveme();

	string returnname();

	~Hero();
};

#endif

