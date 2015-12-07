#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "GameManager.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d;

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

	GameManager::sharedGameManager()->isGameLive = false;

    return true;
}

void HelloWorld::UpButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	if (GameManager::sharedGameManager()->isGameLive)
	{
		CCLOG("In touch &d", type);
		Vec2 currentPos = Tank->getPosition();

		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			if (currentPos.y < 468)
			{
				Tank->setPosition(currentPos.x, currentPos.y += 113);
			}
		}
	}

}

void HelloWorld::DownButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	if (GameManager::sharedGameManager()->isGameLive)
	{
		CCLOG("In touch &d", type);
		Vec2 currentPos = Tank->getPosition();

		if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		{
			if (currentPos.y > 242)
			{
				Tank->setPosition(currentPos.x, currentPos.y -= 113);
			}
		}
	}
}

void HelloWorld::StartButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		this->StartGame();
	}

	this->StartGame();
}

void HelloWorld::StartGame()
{
	auto winSize = Director::getInstance()->getVisibleSize();
	GameManager::sharedGameManager()->isGameLive = true;

	auto moveTo = MoveTo::create(0.5, Vec2(-winSize.width*0.5f, winSize.height*0.5f));
	StartButton->runAction(moveTo);
}

void HelloWorld::EndGame()
{
	auto winSize = Director::getInstance()->getVisibleSize();
	GameManager::sharedGameManager()->isGameLive = false;

	auto moveTo = MoveTo::create(0.5, Vec2(winSize.width*0.5f, winSize.height*0.5f));
	StartButton->runAction(moveTo);
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	cocos2d::log("touch began");
	return true;
}

void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
	cocos2d:log("touch ended");
}

void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
	cocos2d::log("touch moved");
}

void HelloWorld::onTouchCancelled(Touch* touch, Event* event)
{
	cocos2d::log("touch cancelled");
}

void HelloWorld::update(float delta)
{

	GameManager::sharedGameManager()->AddToScore(1);
	if (GameManager::sharedGameManager()->isGameLive)
	{
		Vec2 currentPos = Tank->getPosition();
		Tank->setPosition(currentPos.x, currentPos.y);

		int score = GameManager::sharedGameManager()->GetScore();
		if (score % 60 == 0)
		{
			if (wave = false)
			{

			}
		}
	}

}