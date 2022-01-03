#include "Bullet.h"
#include "Transform2D.h"
#include "MovementComponent.h"
#include "Sprite.h"


void Bullet::start()
{
	Actor::start();
	m_sprite = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/bullet.png")));
	m_movementComponent = dynamic_cast<MovementComponent*>(addComponent(new MovementComponent()));
	m_movementComponent->setMaxSpeed(1000);
	m_movementComponent->setVelocity(m_bulletDirection);
}

void Bullet::update(float deltaTime)
{
	Actor::update(deltaTime);

	getTransform()->getLocalPosition() = getTransform()->getLocalPosition() + m_bulletDirection.getNormalized() * m_speed * deltaTime;
}

void Bullet::onCollision(Actor* other)
{
}
