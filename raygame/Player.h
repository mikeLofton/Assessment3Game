#pragma once
#include "Actor.h"
class InputComponent;
class MovementComponent;
class Sprite;

class Player :
	public Actor
{
public:
	/// <summary>
	/// Player Constructor
	/// </summary>
	/// <param name="x">Players x position</param>
	/// <param name="y">Plyaers y position</param>
	/// <param name="name">Players name</param>
	Player(float x, float y, const char* name) : Actor(x, y, name) {}

	/// <summary>
	/// In start all componenets need for player are added
	/// and the max speed is set.
	/// </summary>
	void start() override;

	/// <summary>
	/// Updates player input
	/// </summary>
	/// <param name="deltaTime">Elapsed time</param>
	void update(float deltaTime) override;

	/// <summary>
	/// Draws the collider
	/// </summary>
	void draw() override;

	/// <summary>
	/// When player collides with the Enemy player respawns
	/// When player collides with the power up the player's scale and radius decrease
	/// to evade enemies easier.
	/// </summary>
	/// <param name="other"></param>
	void onCollision(Actor* other) override;

private:
	InputComponent* m_inputComponent;
	MovementComponent* m_moveComponent;
	Sprite* m_spriteComponent;
};

