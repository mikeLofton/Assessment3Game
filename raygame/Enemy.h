#pragma once
#include "Actor.h"
class MovementComponent;
class Sprite;
class Transform2D;

class Enemy :
	public Actor
{
public:

	/// <param name="x">The enemy's starting x position</param>
	/// <param name="y">The enemy's starting y position</param>
	/// <param name="name">The enemy's name</param>
	/// <param name="target">The target the enemy chases</param>
	Enemy(float x, float y, const char* name, Actor* target) : Actor(x, y, name) { m_target = target; }

	//Destructor
	~Enemy();

	//Called when the program starts
	void start() override;

	//Called every frame
	void update(float deltaTime) override;

	//Called every frame / draws sprites
	void draw() override;

	//What occurs on collision
	void onCollision(Actor* other) override;
	

private:
	MovementComponent* m_moveComponent;
	Sprite* m_spriteComponent;
	Actor* m_target;
};

