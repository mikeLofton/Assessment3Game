#include "Enemy.h"
#include "MovementComponent.h"
#include "Sprite.h"
#include "Transform2D.h"

void Enemy::start()
{
	Actor::start();
	m_moveComponent = dynamic_cast<MovementComponent*>(addComponent(new MovementComponent()));
	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/enemy.png")));
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);

	MathLibrary::Vector2 direction;
	direction = m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition();
	direction.normalize();
	m_moveComponent->setVelocity(direction * 100);
	this->getTransform()->lookAt(m_target->getTransform()->getWorldPosition());
}
