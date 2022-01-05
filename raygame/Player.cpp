#include "Player.h"
#include "InputComponent.h"
#include "MovementComponent.h"
#include "Sprite.h"
#include "Engine.h"
#include "Bullet.h"
#include "Transform2D.h"
#include "Scene.h"

void Player::start()
{
	Actor::start();

	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MovementComponent*>(addComponent(new MovementComponent()));
	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/player.png")));
	
	//Set spawn point
	//Set move speed
	//Set position clamps
}

void Player::update(float deltaTime)
{
	m_sinceLastShot += deltaTime;

	

	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	m_moveComponent->setVelocity(moveDirection * 200);
	if (m_sinceLastShot > m_cooldown)
	{
		if (m_inputComponent->checkActionKey())
		{
			Bullet* bullet = new Bullet(this, getTransform()->getLocalPosition().x, getTransform()->getLocalPosition().y, getTransform()->getForward(), 150, "bullet");
			bullet->getTransform()->setScale({ 50, 50 });
			
			/*bullet->getTransform()->setLocalPosition(this->getTransform()->getLocalPosition);

			bullet->getTransform()->setForward(this->getTransform()->getForward);*/

			Engine::getCurrentScene()->addActor(bullet);
			m_sinceLastShot = 0;

			if (m_sinceLastShot > m_cooldown)
				delete bullet;
		}
	}
	
	Actor::update(deltaTime);
}
