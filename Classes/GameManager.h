//
//  GameManger.h
//  CocosProject


#ifndef __CocosProject__GameManager__
#define __CocosProject__GameManager__

#include <stdio.h>

class GameManager
{
public:
	~GameManager();
	static GameManager* sharedGameManager();

	void AddToScore(int increment);
	void ResetScore();
	int GetScore();

	bool isGameLive;

private:
	GameManager();
	static GameManager* instance;

	int score;
};
#endif /* defined(__CocosProject__GameManger__) */