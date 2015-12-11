#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "GameManager.h"
#include "ui/CocosGUI.h"
#include "stdio.h"

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

	scoreLabel = (cocos2d::ui::Text*)rootNode->getChildByName("label");
	Highscore = (cocos2d::ui::Text*)rootNode->getChildByName("High");

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
		HelloWorld::EndGame();
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

	GameManager::sharedGameManager()->ResetScore();
}

void HelloWorld::EndGame()
{
	auto winSize = Director::getInstance()->getVisibleSize();
	GameManager::sharedGameManager()->isGameLive = false;

	auto moveTo = MoveTo::create(0.5, Vec2(winSize.width*0.5f, winSize.height*0.5f));
	StartButton->runAction(moveTo);

	if (GameManager::sharedGameManager()->GetScore() > HighScore)
	{
		HighScore = GameManager::sharedGameManager()->GetScore();
		Highscore->setString(StringUtils::format("High Score: %d", HighScore));
	}
	
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
	if (GameManager::sharedGameManager()->isGameLive)
	{
		Vec2 currentPos = Tank->getPosition();
		Tank->setPosition(currentPos.x, currentPos.y);



		GameManager::sharedGameManager()->AddToScore(1);

		int score = GameManager::sharedGameManager()->GetScore();

		scoreLabel->setString(StringUtils::format("Score: %d", GameManager::sharedGameManager()->GetScore()));

		if (score % 250 == 0)
		{
			if (wave = false)
			{
				int spawn = 0;

				if (score > 10000)
				{
					for (int i = 0; i < 1; i++)
					{
						while (row = false)
						{
							int rowNum = (CCRANDOM_0_1() * 3) + 1;

							if (rowNum == 1)
							{
								while (row1 = false)
								{
									spawnX = 1136;
									spawnY = 242;

									row1 = true;
									row = true;
								}
							}
							else if (rowNum == 2)
							{
								while (row2 = false)
								{
									spawnX = 1136;
									spawnY = 355;

									row2 = true;
									row = true;
								}
							}
							else if (rowNum == 3)
							{
								while (row3 = false)
								{
									spawnX = 1136;
									spawnY = 468;

									row3 = true;
									row = true;
								}
							}
							else if (rowNum == 4)
							{
								while (row4 = false)
								{
									spawnX = 1136;
									spawnY = 581;

									row4 = true;
									row = true;
								}
							}
						}
						row = false;

						while (enemy = false)
						{
							int enemyNum = (CCRANDOM_0_1() * 8) + 1;

							if (enemyNum == 1)
							{
								while (tank1 = false)
								{
									EnemyTank(int spawnX, int spawnY);

									tank1 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 2)
							{
								while (tank2 = false)
								{
									EnemyTank(int spawnX, int spawnY)

										tank2 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 3)
							{
								while (tank3 = false)
								{
									EnemyTank(int spawnX, int spawnY);

									tank3 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 4)
							{
								while (barrel1)
								{
									Barrel(int spawnX, int spawnY);

									barrel1 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 5)
							{
								while (barrel2 = false)
								{
									Barrel(int spawnX, int spawnY);

									barrel2 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 6)
							{
								while (barrel3 = false)
								{
									Barrel(int spawnX, int spawnY);

									barrel3 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 7)
							{
								while (wall1 = false)
								{
									Wall(int spawnX, int spawnY);

									wall1 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 8)
							{
								while (wall2 = true)
								{
									Wall(int spawnX, int spawnY);

									wall2 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 9)
							{
								while (wall3 = true)
								{
									Wall(int spawnX, int spawnY);

									wall3 = true;
									enemy = true;
								}
							}
						}
						enemy = false;
					}
				}
				else if (10000 < score < 20000)
				{
					for (int i = 0; i < 2; i++)
					{
						while (row = false)
						{
							int rowNum = (CCRANDOM_0_1() * 3) + 1;

							if (rowNum == 1)
							{
								while (row1 = false)
								{
									spawnX = 1136;
									spawnY = 242;

									row1 = true;
									row = true;
								}
							}
							else if (rowNum == 2)
							{
								while (row2 = false)
								{
									spawnX = 1136;
									spawnY = 355;

									row2 = true;
									row = true;
								}
							}
							else if (rowNum == 3)
							{
								while (row3 = false)
								{
									spawnX = 1136;
									spawnY = 468;

									row3 = true;
									row = true;
								}
							}
							else if (rowNum == 4)
							{
								while (row4 = false)
								{
									spawnX = 1136;
									spawnY = 581;

									row4 = true;
									row = true;
								}
							}
						}
						row = false;

						while (enemy = false)
						{
							int enemyNum = (CCRANDOM_0_1() * 8) + 1;

							if (enemyNum == 1)
							{
								while (tank1 = false)
								{
									EnemyTank(int spawnX, int spawnY);

									tank1 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 2)
							{
								while (tank2 = false)
								{
									EnemyTank(int spawnX, int spawnY)

										tank2 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 3)
							{
								while (tank3 = false)
								{
									EnemyTank(int spawnX, int spawnY);

									tank3 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 4)
							{
								while (barrel1)
								{
									Barrel(int spawnX, int spawnY);

									barrel1 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 5)
							{
								while (barrel2 = false)
								{
									Barrel(int spawnX, int spawnY);

									barrel2 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 6)
							{
								while (barrel3 = false)
								{
									Barrel(int spawnX, int spawnY);

									barrel3 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 7)
							{
								while (wall1 = false)
								{
									Wall(int spawnX, int spawnY);

									wall1 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 8)
							{
								while (wall2 = true)
								{
									Wall(int spawnX, int spawnY);

									wall2 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 9)
							{
								while (wall3 = true)
								{
									Wall(int spawnX, int spawnY);

									wall3 = true;
									enemy = true;
								}
							}
						}
						enemy = false;
					}
				}
				else if (20000 < score)
				{
					for (int i = 0; i < 3; i++)
					{
						while (row = false)
						{
							int rowNum = (CCRANDOM_0_1() * 3) + 1;

							if (rowNum == 1)
							{
								while (row1 = false)
								{
									spawnX = 1136;
									spawnY = 242;

									row1 = true;
									row = true;
								}
							}
							else if (rowNum == 2)
							{
								while (row2 = false)
								{
									spawnX = 1136;
									spawnY = 355;

									row2 = true;
									row = true;
								}
							}
							else if (rowNum == 3)
							{
								while (row3 = false)
								{
									spawnX = 1136;
									spawnY = 468;

									row3 = true;
									row = true;
								}
							}
							else if (rowNum == 4)
							{
								while (row4 = false)
								{
									spawnX = 1136;
									spawnY = 581;

									row4 = true;
									row = true;
								}
							}
						}
						row = false;

						while (enemy = false)
						{
							int enemyNum = (CCRANDOM_0_1() * 8) + 1;

							if (enemyNum == 1)
							{
								while (tank1 = false)
								{
									EnemyTank(int spawnX, int spawnY);

									tank1 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 2)
							{
								while (tank2 = false)
								{
									EnemyTank(int spawnX, int spawnY)

										tank2 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 3)
							{
								while (tank3 = false)
								{
									EnemyTank(int spawnX, int spawnY);

									tank3 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 4)
							{
								while (barrel1)
								{
									Barrel(int spawnX, int spawnY);

									barrel1 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 5)
							{
								while (barrel2 = false)
								{
									Barrel(int spawnX, int spawnY);

									barrel2 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 6)
							{
								while (barrel3 = false)
								{
									Barrel(int spawnX, int spawnY);

									barrel3 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 7)
							{
								while (wall1 = false)
								{
									Wall(int spawnX, int spawnY);

									wall1 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 8)
							{
								while (wall2 = true)
								{
									Wall(int spawnX, int spawnY);

									wall2 = true;
									enemy = true;
								}
							}
							else if (enemyNum == 9)
							{
								while (wall3 = true)
								{
									Wall(int spawnX, int spawnY);

									wall3 = true;
									enemy = true;
								}
							}
						}
						enemy = false;
					}
				}
			}
		}
	}
}





/*}
				else if (10000 > score > 20000)
				{
					spawn = 2;
				}
				else if (20000 > score)
				{
					spawn = 3;
				}*/