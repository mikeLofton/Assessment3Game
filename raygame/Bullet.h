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
	/// <summary>
	/// Bullet constructor
	/// </summary>
	/// <param name="owner">The actor the bullet is attached to</param>
	/// <param name="x">The x position of bullet</param>
	/// <param name="y">THe y position of bullet</param>
	/// <param name="bulletDirection">the direction the bullet will travel</param>
	/// <param name="speed">The speed of the bullet</param>
	/// <param name="name">Bullet name</param>
	Bullet(Actor* owner, float x, float y, MathLibrary::Vector2 bulletDirection, float speed, const char* name) : Actor::Actor(x, y, name) { m_owner = owner; m_bulletDirection = bulletDirection; m_speed = speed; }
	~Bullet() {};

	/// <summary>
	/// How fast the bullet is going
	/// </summary>
	/// <param name="speed">bullet speed</param>
	/// <returns></returns>
	float speed(float speed) { m_speed = speed; }

	/// <summary>
	/// Function adds the sprite and move component to the bullet
	/// Sets the velocity of the bullet
	/// Attaches a collider for the bullet
	/// </summary>
	void start() override;

	/// <summary>
	/// Sets the direction the bullet should be traveling in 
	/// and despawns the bullet after a certain amount of time.
	/// </summary>
	/// <param name="deltaTime">Elapsed time</param>
	void update(float deltaTime) override;

	/// <summary>
	/// Draws the bullet collider
	/// </summary>
	void draw() override;

	/// <summary>
	/// When bullet collides with an enemy the bullet despawns.
	/// </summary>
	/// <param name="other"></param>
	void onCollision(Actor* other) override;


private:
	float m_speed;
	MathLibrary::Vector2 m_bulletDirection;
	MovementComponent* m_movementComponent;
	Sprite* m_sprite;
	Actor* m_owner;

	//The amount of time that has passed since player has shot a bullet
	float m_timeSinceLastShot = 1;
	//The amount of time that it takes for a bullet to despawn
	float m_coolDown = 20;
};

