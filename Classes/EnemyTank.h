#ifndef __EnemyTank_H__
#define __EnemyTank_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class EnemyTank
{
public: 
	EnemyTank(int x, int y);
	~EnemyTank();

	bool Dead;
	int speed;

};
#endif