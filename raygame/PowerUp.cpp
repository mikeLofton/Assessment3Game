#include "PowerUp.h"
#include "Bullet.h"
#include "Sprite.h"
#include "CircleCollider.h"
#include "Engine.h"
#include "Transform2D.h"
#include <iostream>
#include "Player.h"
#include "MovementComponent.h"
#include "raymath.h"
#include <cstdlib>
#include <time.h>

void PowerUp::start()
{
	Actor::start();
	//Power up sprite
	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/Flameless.png")));
	m_movementComponent = dynamic_cast<MovementComponent*>(addComponent(new MovementComponent()));
	m_movementComponent->setMaxSpeed(10);

	//The power ups sprite
	CircleCollider* powerUpCircleCollider = new CircleCollider(10, this);
	this->setCollider(powerUpCircleCollider);
}

void PowerUp::update(float deltaTime)
{
	Actor::update(deltaTime);

	srand(time(NULL));
	float range = rand() % 100 + 1;
	
	m_movementComponent->setVelocity({ 30,0 });
	
	if (range < 60 || range > 10)
	{
		m_movementComponent->setVelocity({ 0, 30 });
		
	}
	if (range > 50 || range < 30)
	{
		m_movementComponent->setVelocity({ 30,0 });
		
	}
	if (range > 70 || range < 40)
	{
		m_movementComponent->setVelocity({ -30, 0 });
	}
	if (range < 80 || range > 90)
	{
		m_movementComponent->setVelocity({ 0, -30 });
	}
	else
	{
		srand(1);
	}

	float posX = Clamp(getTransform()->getLocalPosition().x, 30, 680);
	float posY = Clamp(getTransform()->getLocalPosition().y, 30, 930);
	getTransform()->setLocalPosition(MathLibrary::Vector2(posX, posY));

	if (getTransform()->getWorldPosition().x >= 679)
		m_movementComponent->setVelocity({ -30, 0 });
}

void PowerUp::draw()
{
	Actor::draw();
	//Draw Collider
	//getCollider()->draw();
}
