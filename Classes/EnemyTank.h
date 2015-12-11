//
//  EnemyTank.h
//  CocosProject
//

#ifndef __CocosProject__EnemyTank__
#define __CocosProject__EnemyTank__

#include <stdio.h>


class EnemyTank : public cocos2d::Node
{
public:
	EnemyTank();
	~EnemyTank();

	virtual bool init() override;
	static EnemyTank* create();

	void    update(float);

	bool    hasCollidedWithAEnemyTank(cocos2d::Rect collisionBoxToCheck);
	void    reset();

private:
	cocos2d::Sprite* Enemy_Tank;
	float       currentSpeed;


};




#endif 