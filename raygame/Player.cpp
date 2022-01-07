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
		Bullet* bullet = new Bullet(this, getTransform()->getLocalPosition().x, getTransform()->getLocalPosition().y, getTransform()->getForward(), 550, "Bullet");
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

void Player::draw()
{
	Actor::draw();
	getCollider()->draw();
}

void Player::onCollision(Actor* other)
{
	//If player collides with enemy...
	if (other->getName() == "Enemy")
	{
		//...player respawns.
		this->getTransform()->setLocalPosition(MathLibrary::Vector2(50, 500));
	}

	//If player collides with the power up...
	if (other->getName() == "Power Up")
	{
		//...removes the power up from the start scene
		Engine::destroy(other);

		//scales the player down when collides with power up
		this->getTransform()->scale({ 0.2, 0.2 });
		//create new collider with a smaller radius
		CircleCollider* newCollider = new CircleCollider(1, this);
		this->setCollider(newCollider);

		//PowerUp* powerUpChild = new PowerUp(1, 1, "Power Up child");
		//powerUpChild->getTransform()->setScale({ 50, 50 });
		//this->getTransform()->addChild(powerUpChild);
	}

	if (other->getName() == "Power Up 2")
	{
		Engine::destroy(other);

		Bullet* bullet = new Bullet(this, 1, 1, { 0,0 }, 1, "Bullet child");
		Engine::getCurrentScene()->addActor(bullet);
		this->getTransform()->addChild(bullet->getTransform());
		bullet->getTransform()->setScale({ 50, 50 });
		
		

		CircleCollider* bulletChildCollder = new CircleCollider(bullet);
		bullet->setCollider(bulletChildCollder);
		
	}
}


