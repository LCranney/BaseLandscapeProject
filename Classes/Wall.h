#ifndef __Wall_H__
#define __Wall_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Wall
{
public:
	Wall(int x, int y);
	~Wall();

	bool Dead;
	int speed;

};
#endif