#include "Wall.h"
#include "cocostudio/CocoStudio.h"
#include "GameManager.h"

using namespace cocos2d;

Wall* Wall::create()
{
	Wall* myNode = new Wall();
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

bool Wall::init()
{
	if (!Node::init())
	{
		return false;
	}

	//Load this object in from cocos studio.
	auto rootNode = CSLoader::createNode("Enemy_Tank.csb");
	addChild(rootNode);

	this->scheduleUpdate();

	wall = (Sprite*)rootNode->getChildByName("Wall");

	currentSpeed = 200.0f;

	return true;
}

Wall::Wall()
{
}


Wall::~Wall()
{

}


void Wall::update(float deltaTime)
{
}

bool Wall::hasCollidedWithAWall(Rect collisionBoxToCheck)
{
	Rect modifiedWall;
	modifiedWall.size = wall->getBoundingBox().size;
	modifiedWall.origin = convertToWorldSpaceAR(wall->getBoundingBox().origin);

	if (modifiedWall.intersectsRect(collisionBoxToCheck))
	{
		return true;
	}
	return false;
}