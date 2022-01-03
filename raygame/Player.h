#pragma once
#include "Actor.h"
class InputComponent;
class MovementComponent;
class Sprite;
class Scene;

class Player :
	public Actor
{
public:
	Player(float x, float y, const char* name) : Actor(x, y, name) {}

	void start() override;
	void update(float deltaTime) override;

private:
	InputComponent* m_inputComponent;
	MovementComponent* m_moveComponent;
	Sprite* m_spriteComponent;
	float m_sinceLastShot;
	float m_cooldown = 1;
};

