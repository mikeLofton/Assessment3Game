#pragma once
#include "Actor.h"
class GameManager :
	public Actor
{
public:

	GameManager(float x, float y, const char* name) : Actor(x, y, name) {}

	void update(float deltaTime) override;

private:
	
};

