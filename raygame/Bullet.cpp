#include "Bullet.h"
#include "Transform2D.h"
#include "MovementComponent.h"
#include "Sprite.h"


void Bullet::update(float deltaTime)
{
	m_movementComponent = dynamic_cast<MovementComponent*>(addComponent(new MovementComponent()));
	m_movementComponent->setMaxSpeed(10);
	getTransform()->getLocalPosition() = getTransform()->getLocalPosition() + m_bulletDirection.getNormalized() * m_speed * deltaTime;
	m_sprite = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/bullet.png")));
}

void Bullet::onCollision(Actor* other)
{
}
