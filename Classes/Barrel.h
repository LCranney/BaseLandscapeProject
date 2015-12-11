#ifndef __Barrel_H__
#define __Barrel_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Barrel
{
public:
	Barrel(int x, int y);
	~Barrel();

	bool Dead;
	int speed;

};
#endif