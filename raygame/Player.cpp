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
	//Draw Collider
	getCollider()->draw();
}

void Player::onCollision(Actor* other)
{
	//If player collides with enemy...
	if (other->getName() == "Enemy")
	{
		//...player respawns.
		this->getTransform()->setLocalPosition(MathLibrary::Vector2(50, 500));

		if (lifeCount == 3)
			m_playerLifeComponent->removeLife3();
		else if (lifeCount == 2)
			m_playerLifeComponent->removeLife2();
		else if (lifeCount == 1)
			m_playerLifeComponent->removeLife1();


		lifeCount--;
		
		this->getTransform()->setScale({ 50,50 });
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
		m_moveComponent->setMaxSpeed(20);

		
	}
	
	//If player collides with the second power up...
	if (other->getName() == "Power Up 2")
	{
		//...destroy the power up sprite
		Engine::destroy(other);

		//Create bullet that is childed to player
		Bullet* bullet = new Bullet(this, 1, 1, { 0, 0 }, 1, "Bullet child");
		Engine::getCurrentScene()->addActor(bullet);
		this->getTransform()->addChild(bullet->getTransform());
		bullet->getTransform()->setScale({ 50,50 });
		bullet->getTransform()->setTranslation(1, 1);
		//Bullet 1 collider
		CircleCollider* bulletChildCollder = new CircleCollider(bullet);
		bullet->setCollider(bulletChildCollder);
		
		//bullet2
		Bullet* bullet2 = new Bullet(this, 1, 1, { 0, 0 }, 1, "Bullet child");
		Engine::getCurrentScene()->addActor(bullet2);
		this->getTransform()->addChild(bullet2->getTransform());
		bullet2->getTransform()->setScale({ 50,50 });
		bullet2->getTransform()->setTranslation(-1, -1);
		//Bullet 2 collider
		CircleCollider* bullet2Collider = new CircleCollider(bullet2);
		bullet2->setCollider(bullet2Collider);

		//Bullet3
		Bullet* bullet3 = new Bullet(this, 1, 1, { 0, 0 }, 1, "Bullet child");
		Engine::getCurrentScene()->addActor(bullet3);
		this->getTransform()->addChild(bullet3->getTransform());
		bullet3->getTransform()->setScale({ 50,50 });
		bullet3->getTransform()->setTranslation(1, -1);
		//Bullet 3 collider
		CircleCollider* bullet3Collider = new CircleCollider(bullet3);
		bullet3->setCollider(bullet3Collider);
		
		//Bullet4
		Bullet* bullet4 = new Bullet(this, 1, 1, { 0, 0 }, 1, "Bullet child");
		Engine::getCurrentScene()->addActor(bullet4);
		this->getTransform()->addChild(bullet4->getTransform());
		bullet4->getTransform()->setScale({ 50,50 });
		bullet4->getTransform()->setTranslation(-1, 1);
		//Bullet 4 collider
		CircleCollider* bullet4Collider = new CircleCollider(bullet4);
		bullet4->setCollider(bullet4Collider);

		//Bullet5
		Bullet* bullet5 = new Bullet(this, 1, 1, { 0, 0 }, 1, "Bullet child");
		Engine::getCurrentScene()->addActor(bullet5);
		this->getTransform()->addChild(bullet5->getTransform());
		bullet5->getTransform()->setScale({ 50,50 });
		bullet5->getTransform()->setTranslation(0, 1);
		//Bullet 5 Collider
		CircleCollider* bullet5Collider = new CircleCollider(bullet5);
		bullet5->setCollider(bullet5Collider);

		//Bullet6
		Bullet* bullet6 = new Bullet(this, 1, 1, { 0, 0 }, 1, "Bullet child");
		Engine::getCurrentScene()->addActor(bullet6);
		this->getTransform()->addChild(bullet6->getTransform());
		bullet6->getTransform()->setScale({ 50,50 });
		bullet6->getTransform()->setTranslation(1,0);
		//Bullet 6 Collider
		CircleCollider* bullet6Collider = new CircleCollider(bullet6);
		bullet6->setCollider(bullet6Collider);

		//Bullet7
		Bullet* bullet7 = new Bullet(this, 1, 1, { 0, 0 }, 1, "Bullet child");
		Engine::getCurrentScene()->addActor(bullet7);
		this->getTransform()->addChild(bullet7->getTransform());
		bullet7->getTransform()->setScale({ 50,50 });
		bullet7->getTransform()->setTranslation(-1, 0);
		//Bullet 7 collider
		CircleCollider* bullet7Collider = new CircleCollider(bullet7);
		bullet7->setCollider(bullet7Collider);

		//Bullet8
		Bullet* bullet8 = new Bullet(this, 1, 1, { 0, 0 }, 1, "Bullet child");
		Engine::getCurrentScene()->addActor(bullet8);
		this->getTransform()->addChild(bullet8->getTransform());
		bullet8->getTransform()->setScale({ 50,50 });
		bullet8->getTransform()->setTranslation(0, -1);
		//Bullet 8 collider
		CircleCollider* bullet8Collider = new CircleCollider(bullet8);
		bullet8->setCollider(bullet8Collider);
	}
}


