#include "Hero.h"
#include <string>

Hero::Hero(int h,int a,int d, int s) :Common_(h, a, d)
{
	Special = s;
}

int Hero::prepare_fight() {
	/*prompt if you want to use special fight?*/
	cout << "Do you want to use one of the special fight(Y/N)? " ;
	string YesorNo;
	getline(cin, YesorNo);
	if (!YesorNo.compare("Y")) {
		this->specialAttack();
	}
	this->FightIncrease = getrandom(1, 6);
	this->Attack += this->FightIncrease;
	return this->Attack;
}

int Hero::saveme(){
	if (this->Attack > 0) {
		cout << "Do you want to transfer the attack value into health points(Y/N)? ";
		string YesorNo;
		getline(cin, YesorNo);
		if (!YesorNo.compare("Y")) {
			cout << "How much points you want to transfer? must be less than" << this->Attack +1 << " :";
			int tv;
			cin >> tv;
			tv = tv > this->Attack ? this->Attack : tv;
			this->Attack -= tv;
			this->Health += tv * 2;
		}
	}
	return 1;
}

int Hero::relax_fight() {
	this->Attack -= this->FightIncrease;
	return 1;
}

int Hero::prepare_defence() {
	this->FightIncrease = getrandom(1, 6);
	this->Defence += this->FightIncrease;
	return this->Defence;
}

int Hero::relax_defence() {
	this->Defence -= this->FightIncrease;
	return 1;
}
int Hero::specialAttack() {
	if (this->Special > 0) {
		cout << "Using Special Attack" << endl;
		this->Attack += 1;
		this->Special -= 1;
	}
	else {
		cout << "You don't have any special attack points..." << endl;
	}
	return 1;
}

/* Here, A pointer is used for flexiblity*/
int Hero::fight(Monster *m) {

	int hval = this->prepare_fight();
	int mval = m->prepare_defence();


	cout << "Your attack is " << this->Attack << "\t"
	<< "Monster's defence is " << mval << endl;
	int diff = hval - mval;
	if(diff>0) {
		m->decrease(diff);
	}
	else {
		this->decrease(-diff);
	}
	this->relax_fight();
	m->relax_defence();


	if (this->status() <= 0) {
		this->saveme();

		if (this->status()<=0)
		    return -1;
	}
	if (m->status() <= 0) {
		return 1;
	}
	return 0;
}

int Hero::reward() {
	this->Coins += this->Health;
	this->Health += 20;
	this->Attack += getrandom(0, 2);
	this->Defence += getrandom(0, 2);
	this->Special += getrandom(0, 2);
	limit();
	return 1;
}

void Hero::healthStat() {
	Common_::healthStat();
	cout << "Special Attack:" << this->Special<<"\t"<<"Coins:"<<this->Coins <<endl;
}

int Hero::limit() {
	this->Health = this->Health > 50 ? 50 : this->Health;
	this->Attack = this->Attack > 10 ? 10 : this->Attack;
	this->Special = this->Special > 10 ? 10 : this->Special;
	this->Defence = this->Defence > 10 ? 10 : this->Defence;
	return 1;
}

int Hero :: setname(string str) {
	this->name = str;
	return 1;
}


string Hero::returnname() {
	return(this->name) ;
}

Hero* Hero::instance = 0;

Hero* Hero::getHero(int h, int a, int d, int s) {
	if (instance == 0) {
		instance = new Hero(h, a, d, s);
	}
	else {
		cout << "There is only one hero in a game" << endl;
	}
	return instance;
}


Hero::~Hero()
{
}
