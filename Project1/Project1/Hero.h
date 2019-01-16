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

	/*Prepare the defence*/
	int prepare_defence();
	/*After the defence*/
	int relax_defence();

	/*prepare the fight*/
	int prepare_fight();
	/*after the fight*/
	int relax_fight();

	int fight(Monster *m);

	/*Using the Special Attack*/
	int specialAttack();

	/*Reward after win*/
	int reward();

	/*Output the health state*/
	void healthStat();

	/*Limit the attributes*/
	int limit();

	/*Set and return names*/
	int setname(string str);
	string returnname();

	/*Additional Feature, the last chance that the hero may win*/
	int saveme();


	~Hero();
};

#endif

