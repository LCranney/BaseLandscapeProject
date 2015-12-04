#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	this->scheduleUpdate();
	auto winSize = Director::getInstance()->getVisibleSize();
	HighScore = 0;
	Tank = (Sprite*)rootNode->getChildByName("Player");

	////TOUCHES
	auto touchListener = EventListenerTouchOneByOne::create();

	// Set callbacks for our touch functions.
	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	//StartButton
	StartButton = static_cast<ui::Button*>(rootNode->getChildByName("StartButton"));
	StartButton->addTouchEventListener(CC_CALLBACK_2(HelloWorld::StartButtonPressed, this));
	StartButton->setPosition(Vec2(winSize.width*0.5f, winSize.height*0.5f));

	Up_Button = static_cast<ui::Button*>(rootNode->getChildByName("Up_Button"));
	Up_Button->addTouchEventListener(CC_CALLBACK_2(HelloWorld::UpButtonPressed, this));

	Down_Button = static_cast<ui::Button*>(rootNode->getChildByName("Down_Button"));
	Down_Button->addTouchEventListener(CC_CALLBACK_2(HelloWorld::DownButtonPressed, this));
	Down_Button->setPosition(Vec2(winSize.width*0.5f, winSize.height*0.1f));

    return true;
}
