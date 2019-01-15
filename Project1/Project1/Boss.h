
#include "Monster.h"
class Boss :
	public Monster
{
private:
	int Special;

public:
	Boss(int h, int a, int d, int s);
	int prepare_fight();
	void healthStat();

	~Boss();
};
