/*
Common class for General Monster, Boss and the Hero:
There are common attributes:
	Health:
	Attack:
	Defence:
*/
#ifndef __COMMON__
#define __COMMON__
#include "iostream"
#define random(x) ((rand()+x)%x)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;
class Common_ {
public: 
	int Health;
	int Attack;
	int Defence;
	int FightIncrease;
	string name;
	int getrandom(int lower, int upper) {
		srand((int)time(0)+Health+Attack+Defence+FightIncrease);
		int randres = lower + random((upper - lower+1));
		return randres;

	}

public:

	Common_(int h, int a, int d) {
		Health = h;
		Attack = a;
		Defence = d;
	}
	~Common_() {
	}

	int decrease(int amount) {
		this->Health -= amount;
		return 1;
	}

	int increase(int amount) {
		this->Health += amount;
	}

	virtual int prepare_defence() abstract;
	virtual int relax_defence() abstract;

	virtual int prepare_fight() abstract;
	virtual int relax_fight() abstract;

	int status() {
		return this->Health;
	}

	virtual void healthStat() {
		cout << "Health:" << Health << "\t"
			<< "Attack:" << Attack << "\t"
			<< "Defence:" << Defence << endl;

	}

};

#endif