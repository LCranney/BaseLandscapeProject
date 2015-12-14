#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class EnemyTank;
class Wall;
class Barrel;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void update(float);

	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);

	void StartButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void UpButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void DownButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);

	void StartGame();
	void EndGame();

	int score;
	int spawn;
	int spawnX;
	int spawnY;
	bool wave;
	bool enemy;
	bool row;

	bool tank1;
	bool tank2;
	bool tank3;
	bool tank4;

	bool barrel1;
	bool barrel2;
	bool barrel3;
	bool barrel4;

	bool wall1;
	bool wall2;
	bool wall3;
	bool wall4;

	bool row1;
	bool row2;
	bool row3;
	bool row4;
	bool row5;

private:
	cocos2d::ui::Text*      scoreLabel;
	cocos2d::ui::Text*      Highscore;
	cocos2d::ui::Button*	StartButton;
	cocos2d::ui::Button*	Up_Button;
	cocos2d::ui::Button*	Down_Button;
	cocos2d::Sprite*		Tank;
	cocos2d::Node*          wallNode;
	cocos2d::Node*          enemyTankNode;
	cocos2d::Node*          barrelNode;
	int						HighScore;
	Wall*					wall;
	EnemyTank*				enemyTank;
	Barrel*					barrel;

};

#endif // __HELLOWORLD_SCENE_H__
