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

	/*MathLibrary::Vector2 direction;
	direction = getTransform()->getWorldPosition();
	direction.normalize();
	m_movementComponent->setVelocity(direction * 50);*/
	
	

}

void PowerUp::draw()
{
	Actor::draw();
	//Draw Collider
	//getCollider()->draw();
}
