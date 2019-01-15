#include "Monster.h"

Monster::Monster(int h, int a, int d) :Common_(h, a, d)
{
}

int Monster :: prepare_defence() {
	this->FightIncrease = getrandom(1, 6);
	this->Defence += this->FightIncrease;
	return this->Defence;
}

int Monster::relax_defence() {
	this->Defence -= this->FightIncrease;
	return 1;
}

int Monster::prepare_fight() {
	this->FightIncrease = getrandom(1, 6);
	this->Attack += this->FightIncrease;
	return this->Attack;
}

int Monster::relax_fight() {
	this->Attack -= this->FightIncrease;
	return 1;
}

int Monster::fight(Hero *h) {

	int mval = this->prepare_fight();
	int hval = h->prepare_defence();
	 
	cout << "Monster' attack is " << this->Attack << "\t"
	 << "Your defence is " << hval << endl;
	int diff = mval - hval;
	if (diff > 0) {
		h->decrease(diff);
	}
	else {
		this->decrease(-diff);
	}
	this->relax_fight();
	h->relax_defence();

	if (this->status() <= 0) {
		return 1;
	}
	if (h->status() <= 0) {
		h->saveme();

		if (h->status() <= 0) 
		return -1;
	}
	return 0;
}


Monster::~Monster()
{
}
