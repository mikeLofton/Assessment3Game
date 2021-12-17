#pragma once
#include "Actor.h"
#include <Vector2.h>
class Actor;
class MovementComponent;
class Sprite;

class Bullet :
	public Actor
{
public:
	Bullet(float x, float y, MathLibrary::Vector2 bulletDirection, const char* name) : Actor::Actor(x, y, name) { m_bulletDirection = bulletDirection; }
	~Bullet() {};

	float speed(float speed) { m_speed = speed; }
	void update(float deltaTime) override;
	void onCollision(Actor* other) override;

private:
	float m_speed;
	MathLibrary::Vector2 m_bulletDirection;
	MovementComponent* m_movementComponent;
	Sprite* m_sprite;

};

