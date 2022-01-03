#pragma once
#include "Actor.h"
class MovementComponent;
class Sprite;
class Transform2D;

class Enemy :
	public Actor
{
public:
	Enemy(float x, float y, const char* name, Actor* target) : Actor(x, y, name) { m_target = target; }
	~Enemy();

	void start() override;
	void update(float deltaTime) override;
	/*void onCollision(Actor* other) override;*/

private:
	MovementComponent* m_moveComponent;
	Sprite* m_spriteComponent;
	Actor* m_target;
};

