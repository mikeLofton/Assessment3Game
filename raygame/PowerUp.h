#pragma once
#include "Actor.h"
class MovementComponet;
class Sprite;

class PowerUp :
	public Actor
{
public:
	PowerUp(float x, float y, const char* name) : Actor(x, y, name) { }
	~PowerUp() {}

	void start() override;
	void draw() override;
	void onColision(Actor* other);

private:
	MovementComponet* m_movementComponent;
	Sprite* m_spriteComponent;
};

