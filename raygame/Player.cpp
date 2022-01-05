#include "Player.h"
#include "InputComponent.h"
#include "MovementComponent.h"
#include "Sprite.h"
#include "Transform2D.h"

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
	//Calls the Actor Update
	Actor::update(deltaTime);

	//Creates a move direction Vector2 that takes in the move axis
	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	//Normalizes the move direction
	moveDirection.normalize();

	//Sets the velocity to the move direction times the movement speed
	m_moveComponent->setVelocity(moveDirection * 200);

	//if the magnitude of velocity is greater than zero... 
	if (m_moveComponent->getVelocity().getMagnitude() > 0)
		//...set the players forward to the normalized velocity
		this->getTransform()->setForward(m_moveComponent->getVelocity().getNormalized());
}
