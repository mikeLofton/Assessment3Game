#include "Points.h"
#include "Sprite.h"
#include "MovementComponent.h"
#include "Transform2D.h"
#include "Engine.h"

void Points::start()
{
	Actor::start();
	m_moveComponent = dynamic_cast<MovementComponent*>(addComponent(new MovementComponent()));
	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/Point.png")));
}

void Points::update(float deltaTime)
{
	//Base Actor Update
	Actor::update(deltaTime);

	MathLibrary::Vector2 direction;
	//Direction = the target's world position minus the enemy's world position
	direction = m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition();
	//Normalize the direction
	direction.normalize();
	//Set velocity to the direction times speed
	m_moveComponent->setVelocity(direction * 250);
	//Rotate the enemy to look at the target's world position
	this->getTransform()->lookAt(m_target->getTransform()->getWorldPosition());
}

void Points::draw()
{
	Actor::draw();
}

void Points::onCollision(Actor* other)
{
	if (other->getName() == "Player")
	{
		Engine::destroy(this);
	}
}
