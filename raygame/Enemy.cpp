#include "Enemy.h"
#include "MovementComponent.h"
#include "Sprite.h"
#include "Transform2D.h"
#include "CircleCollider.h"
#include "Engine.h"

void Enemy::start()
{
	//Base Actor start
	Actor::start();
	//Adds the move component
	m_moveComponent = dynamic_cast<MovementComponent*>(addComponent(new MovementComponent()));
	//The Enemy's max speed
	m_moveComponent->setMaxSpeed(10);
	//Adds the sprite component
	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/enemy.png")));
	//The enemy circle collider
	CircleCollider* enemyCollider = new CircleCollider(20, this);
	this->setCollider(enemyCollider);
}

void Enemy::update(float deltaTime)
{
	//Base Actor Update
	Actor::update(deltaTime);

	MathLibrary::Vector2 direction;
	//Direction = the target's world position minus the enemy's world position
	direction = m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition();
	//Normalize the direction
	direction.normalize();
	//Set velocity to the direction times speed
	m_moveComponent->setVelocity(direction * 150);
	//Rotate the enemy to look at the target's world position
	this->getTransform()->lookAt(m_target->getTransform()->getWorldPosition());
}



void Enemy::draw()
{
	Actor::draw();
	//getCollider()->draw();
}

void Enemy::onCollision(Actor* other)
{
	//On collision with bullet or bullet child...
	if (other->getName() == "Bullet" || other->getName() == "Bullet child")
	{
		//Destroy enemy
		Engine::destroy(this);
	}
}
