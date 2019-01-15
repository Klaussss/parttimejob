#include "Boss.h"



Boss::Boss(int h, int a, int d, int s):Monster(h,a,d),Special(s)
{
}

int Boss::prepare_fight() {
	if (this->Special > 0) {
		this->Attack += 1;
		this->Special -= 1;
		cout << "Boss is using the special attack ..."<<endl;
	}
	this->FightIncrease = getrandom(1, 6);
	this->Attack += this->FightIncrease;
	return this->Attack;
}

void Boss::healthStat() {
	Common_::healthStat();
	cout << "Special Attack:" << this->Special <<  endl;
}

Boss::~Boss()
{
}
