#ifndef __CocosProject__Spawning__
#define __CocosProject__Spawning__

#include <stdio.h>

class Spawning
{
public:

	static Spawning* spawn();

	int spawnX;
	int spawnY;
	bool wave;
	bool enemy;
	bool row;

	bool tank1;
	bool tank2;
	bool tank3;
	bool tank4;

	bool barrel1;
	bool barrel2;
	bool barrel3;
	bool barrel4;

	bool wall1;
	bool wall2;
	bool wall3;
	bool wall4;

	bool row1;
	bool row2;
	bool row3;
	bool row4;
	bool row5;

private:

};
#endif

