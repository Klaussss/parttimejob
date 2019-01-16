
// Boss is herited from Monster, with one additional feature: Special attack
#include "Monster.h"
class Boss :
	public Monster
{
private:
	int Special;

public:
	Boss(int h, int a, int d, int s);
	/*Using special Attack before each attack*/
	int prepare_fight();
	void healthStat();

	~Boss();
};
