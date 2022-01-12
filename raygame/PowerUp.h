#pragma once
#include "Actor.h"
class MovementComponent;
class Sprite;

class PowerUp :
	public Actor
{
public:
	/// <summary>
	/// Power up constructor
	/// </summary>
	/// <param name="x">Power up x position</param>
	/// <param name="y">Power up y position</param>
	/// <param name="name">Power up name</param>
	PowerUp(float x, float y, const char* name) : Actor(x, y, name) { }
	~PowerUp() {}

	/// <summary>
	/// Calls base start function and creates the sprite and collider for power up
	/// </summary>
	void start() override;

	void update(float deltaTime) override;

	/// <summary>
	/// Calls the base draw function and draws the collider attached to the power up 
	/// </summary>
	void draw() override;


private:
	MovementComponent* m_movementComponent;
	Sprite* m_spriteComponent;
};

