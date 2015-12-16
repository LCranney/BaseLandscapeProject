#include "Barrel.h"
#include "cocostudio/CocoStudio.h"
#include "GameManager.h"
#include "ui/CocosGUI.h"
#include "stdio.h"

using namespace cocos2d;

Barrel* Barrel::create()
{
	Barrel* myNode = new Barrel();
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

bool Barrel::init()
{
	if (!Node::init())
	{
		return false;
	}

	//Load this object in from cocos studio.
	auto rootNode = CSLoader::createNode("Barrel.csd");
	addChild(rootNode);

	this->scheduleUpdate();

	barrel = (Sprite*)rootNode->getChildByName("Barrel");

	currentSpeed = 200.0f;

	return true;
}

Barrel::Barrel()
{
}


Barrel::~Barrel()
{

}


void Barrel::update(float deltaTime)
{
}

bool Barrel::hasCollidedWithABarrel(Rect collisionBoxToCheck)
{
	Rect modifiedBarrel;
	modifiedBarrel.size = barrel->getBoundingBox().size;
	modifiedBarrel.origin = convertToWorldSpaceAR(barrel->getBoundingBox().origin);

	if (modifiedBarrel.intersectsRect(collisionBoxToCheck))
	{
		return true;
	}
	return false;
}