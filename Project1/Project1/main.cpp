#include "common.h"
#include "Monster.h"
#include "Hero.h"
#include "Boss.h"
#include <malloc.h>
#include <string>

#include<process.h>

#define getresult(result) 			if (result > 0) { \
cout << "You have killed the monster!" << endl;\
h->reward();\
delete m;\
break;\
			}\
else if (result < 0) {\
delete m;\
winner = 0;\
break;\
			}\
else {\
cout << "Keep going" << endl;\
			}\


int main() {

	Monster *m;
	Hero *h = Hero::getHero(20,3,3,2);

	string name;
	cout << "\n\n\n\n\n\n\n\n\n\n"
		<<"\t\t\t\t+++++++++++++++++++++++++++++++++++++++"
		<< "\n\n\t\t\t\t\tWelcome to the \"Hero Quest\"\n\n"
		<<"\t\t\t\t+++++++++++++++++++++++++++++++++++++++"
		<<"\n\n\n\n\n\n\n\n\n\n"
		<< endl;
	cout << "Please input your name:";
	getline(cin, name);

	h->setname(name);

	int NMonster = 4;
	int Monsterpar[4][3] = { {10,1,1},{20,3,2},{30,5,4},{40,6,7} };
	int BOSS[4] = {50,8,8,5};
	
	int result = 0;
	int winner = 1;
	/*Fight against the monsters ... */
	for (int im = 0; im < NMonster; im++) {

		system("cls");
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$" 
		<< "Here comes the Monster " << (im + 1) 
		<< "$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		m = new Monster(Monsterpar[im][0], Monsterpar[im][1], Monsterpar[im][2]);
		while (1) {
			cout << "+++++++++++++++++++++++" 
			 <<"Your turn"  
			 <<"+++++++++++++++++++++++" << endl;

			cout << "Your health stat" << endl;
			h->healthStat();
			cout << "Monster health stat" << endl;
			m->healthStat();

			result = h->fight(m);
			getresult(result);

			cout << "+++++++++++++++++++++++" 
			<< "Monster's turn" 
			<< "+++++++++++++++++++++++" << endl;
			cout << "Your health stat" << endl;
			h->healthStat();
			cout << "Monster health stat" << endl;
			m->healthStat();

			result = m->fight(h);
			getresult(result);
		}
		if (!winner) {
			break;
		}
	}

	if (winner) {
		/*Fight againt the boss ... */
		system("cls");
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$"
			<< "Here comes the BOSS " 
			<< "$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		m = new Boss(50, 8, 8, 5);
		while (1) {
			cout << "+++++++++++++++++++++++"
				<< "Your turn"
				<< "+++++++++++++++++++++++" << endl;

			cout << "Your health stat" << endl;
			h->healthStat();
			cout << "Boss health stat" << endl;
			m->healthStat();

			result = h->fight(m);
			getresult(result);

			cout << "+++++++++++++++++++++++"
				<< "Boss's turn"
				<< "+++++++++++++++++++++++" << endl;
			cout << "Your health stat" << endl;
			h->healthStat();
			cout << "Boss health stat" << endl;
			m->healthStat();

			result = m->fight(h);
			getresult(result);
		}
	}

	system("cls");

	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "-----------------------------------------------------------------------------------------" << endl;
	if (winner) {
		cout << "\t\t\tCongratulations "<<h->returnname()<<", you win the game!!! Welcome back!" << endl;
	}
	else {
		cout << "\t\t\tSorry "<<h->returnname()<<", you lose the game. Try again later!" << endl;
	}
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << " Press enter to quit" << endl;
	string input;
	getline(cin, input);

}