#pragma once
#include "Actor.h"
class Sprite;
class MovementComponent;

class Points :
	public Actor
{
public:
	Points(float x, float y, const char* name, Actor* target) : Actor(x, y, name) { m_target = target; }


	//Called when the program starts
	void start() override;

	//Called every frame
	void update(float deltaTime) override;

	//Called every frame / draws sprites
	void draw() override;

	//What occurs on collision
	void onCollision(Actor* other) override;

private:
	Actor* m_target;
	MovementComponent* m_moveComponent;
	Sprite* m_spriteComponent;
};

