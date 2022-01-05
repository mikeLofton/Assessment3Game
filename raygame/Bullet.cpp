#include "Bullet.h"
#include "Transform2D.h"
#include "MovementComponent.h"
#include "Sprite.h"
#include "Engine.h"


void Bullet::start()
{
	Actor::start();
	m_sprite = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/bullet.png")));
	m_movementComponent = dynamic_cast<MovementComponent*>(addComponent(new MovementComponent()));
	
	m_movementComponent->setVelocity(m_bulletDirection * m_speed);
}

void Bullet::update(float deltaTime)
{
	Actor::update(deltaTime);

	m_timeSinceLastShot = m_timeSinceLastShot + deltaTime;

	getTransform()->getLocalPosition() = getTransform()->getLocalPosition() + m_bulletDirection.getNormalized() * m_speed * deltaTime;

	if (m_timeSinceLastShot > m_coolDown)
	{
		Engine::getCurrentScene()->removeActor(this);
		delete m_sprite;
		m_timeSinceLastShot = 0;
	}
}

void Bullet::onCollision(Actor* other)
{

}
