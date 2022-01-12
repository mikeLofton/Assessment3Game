#pragma once
#include "Actor.h"
class UIText;

class GameManager :
	public Actor
{
public:
	GameManager(float x, float y, const char* name) : Actor(x, y, name){}

	void start() override;
	void update(float deltaTime) override;

	static int enemyCount;
	static int lifeCount;

private:
	UIText* m_winText;
	UIText* m_loseText;
};

