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
	//Add the input component to player
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	//Add the movement component to player
	m_moveComponent = dynamic_cast<MovementComponent*>(addComponent(new MovementComponent()));
	//The the max speed the player can move
	m_moveComponent->setMaxSpeed(10);
	//Add the sprite component for the player ship
	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/player.png")));
	
	//Set spawn point
	//Set move speed
	//Set position clamps
}

void Player::update(float deltaTime)
{
	//Calls the Actor Update
	Actor::update(deltaTime);

	//If player has pressed the spacebar...
	if (m_inputComponent->checkActionKey())
	{
		//...bullet spawns
		Bullet* bullet = new Bullet(this, getTransform()->getLocalPosition().x, getTransform()->getLocalPosition().y, getTransform()->getForward(), 550, "bullet");
		bullet->getTransform()->setScale({ 50, 50 });
	
		//bullet is add to the actor array and to the current scene
		Engine::getCurrentScene()->addActor(bullet);
	}

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
