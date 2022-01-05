#pragma once
#include "Actor.h"
#include <Vector2.h>
class MovementComponent;
class Sprite;
class Actor;

class Bullet :
	public Actor
{
public:
	Bullet(Actor* owner, float x, float y, MathLibrary::Vector2 bulletDirection, float speed, const char* name) : Actor::Actor(x, y, name) { m_owner = owner; m_bulletDirection = bulletDirection; m_speed = speed; }
	~Bullet() {};

	float speed(float speed) { m_speed = speed; }
	void start() override;
	void update(float deltaTime) override;
	void onCollision(Actor* other) override;

private:
	float m_speed;
	MathLibrary::Vector2 m_bulletDirection;
	MovementComponent* m_movementComponent;
	Sprite* m_sprite;
	Actor* m_owner;
};

