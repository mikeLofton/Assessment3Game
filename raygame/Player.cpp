#include "Player.h"
#include "InputComponent.h"
#include "MovementComponent.h"
#include "Sprite.h"
#include "Engine.h"
#include "Bullet.h"
#include "Transform2D.h"
#include "Scene.h"
#include "CircleCollider.h"
#include "PowerUp.h"
#include <iostream>
#include <raymath.h>
#include "PlayerLife.h"

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

	m_playerLifeComponent = dynamic_cast<PlayerLife*>(addComponent(new PlayerLife()));
	

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

	/*if (lifeCount <= 0)
		Engine::CloseApplication();*/


	//Sets the player's boundaries on the screen
	float posX = Clamp(getTransform()->getLocalPosition().x, 30, 680);
	float posY = Clamp(getTransform()->getLocalPosition().y, 30, 930);
	getTransform()->setLocalPosition(MathLibrary::Vector2(posX, posY));
}

void Player::draw()
{
	Actor::draw();
	getCollider()->draw();
}

void Player::onCollision(Actor* other)
{
	if (other->getName() == "Enemy")
	{
		this->getTransform()->setLocalPosition(MathLibrary::Vector2(50, 500));

		if (lifeCount == 3)
			m_playerLifeComponent->removeLife3();
		else if (lifeCount == 2)
			m_playerLifeComponent->removeLife2();
		else if (lifeCount == 1)
			m_playerLifeComponent->removeLife1();


		lifeCount--;
		
	}

	if (other->getName() == "Power Up")
	{
		//Removes the power up from the start scene
		Engine::getCurrentScene()->removeActor(other);
		//Scales the player down when collides with power up
		this->getTransform()->scale({ 0.2, 0.2 });
		CircleCollider* newCollider = new CircleCollider(1, this);
		this->setCollider(newCollider);
		//PowerUp* powerUpChild = new PowerUp(1, 1, "Power Up child");
		//powerUpChild->getTransform()->setScale({ 50, 50 });
		//this->getTransform()->addChild(powerUpChild);
	}
}


