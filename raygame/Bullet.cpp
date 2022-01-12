#include "Bullet.h"
#include "Transform2D.h"
#include "MovementComponent.h"
#include "Sprite.h"
#include "Engine.h"
#include "CircleCollider.h"


void Bullet::start()
{
	Actor::start();
	//Add the sprite component for the bullet
	m_sprite = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/bullet.png")));
	//Add move component for how the bullet will move
	m_movementComponent = dynamic_cast<MovementComponent*>(addComponent(new MovementComponent("Movement Component")));
	//Set the velocity of the bullet
	m_movementComponent->setVelocity(m_bulletDirection * m_speed);

	CircleCollider* bulletCollider = new CircleCollider(10, this);
	this->setCollider(bulletCollider);
}

void Bullet::update(float deltaTime)
{
	Actor::update(deltaTime);

	/*if (getName() == "Bullet child")
		getTransform()->rotate(deltaTime);*/

	//The amount of time that has passed since player has last shot a bullet + the delta time
	m_timeSinceLastShot = m_timeSinceLastShot + deltaTime;

	//The direction the bullet will travel and at what speed
	getTransform()->getLocalPosition() = getTransform()->getLocalPosition() + m_bulletDirection.getNormalized() * m_speed * deltaTime;

	//If the time that the bullet was last shot is greater than the cooldown(3 seconds)...
	if (m_timeSinceLastShot > m_coolDown)
	{
		//...remove the bullet from the actor array and the current scene
		Engine::destroy(this);
		//set the time since the last shot back to 0
		m_timeSinceLastShot = 0;
	}

	
}

void Bullet::draw()
{
	Actor::draw();
	//getCollider()->draw();
}

void Bullet::onCollision(Actor* other)
{
	//If bullet collides with enemy...
	if (other->getName() == "Enemy")
	{
		//...The bullet is removed form the scene
		Engine::destroy(this);
	}

}

