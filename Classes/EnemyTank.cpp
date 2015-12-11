#include "EnemyTank.h"
#include "cocostudio/CocoStudio.h"
#include "GameManager.h"

using namespace cocos2d;

EnemyTank* EnemyTank::create()
{
	EnemyTank* myNode = new EnemyTank();
	if (myNode->init())
	{
		myNode->autorelease();
		return myNode;
	}
	else
	{
		CC_SAFE_DELETE(myNode);
		return nullptr;
	}
	return myNode;
}

bool EnemyTank::init()
{
	if (!Node::init())
	{
		return false;
	}

	//Load this object in from cocos studio.
	auto rootNode = CSLoader::createNode("Enemy_Tank.csb");
	addChild(rootNode);

	this->scheduleUpdate();

	Enemy_Tank = (Sprite*)rootNode->getChildByName("Enemy_Tank");

	currentSpeed = 200.0f;

	return true;
}

EnemyTank::EnemyTank()
{
}


EnemyTank::~EnemyTank()
{

}


void EnemyTank::update(float deltaTime)
{
}

bool EnemyTank::hasCollidedWithAEnemyTank(Rect collisionBoxToCheck)
{
	Rect modifiedEnemyTank;
	modifiedEnemyTank.size = Enemy_Tank->getBoundingBox().size;
	modifiedEnemyTank.origin = convertToWorldSpaceAR(Enemy_Tank->getBoundingBox().origin);

	if (modifiedEnemyTank.intersectsRect(collisionBoxToCheck))
	{
		return true;
	}
	return false;
}
