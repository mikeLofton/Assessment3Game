#include "PowerUp.h"
#include "Bullet.h"
#include "Sprite.h"
#include "CircleCollider.h"
#include "Engine.h"
#include "Transform2D.h"
#include <iostream>

void PowerUp::start()
{
	Actor::start();
	//Power up sprite
	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/bullet.png")));

	//The power ups sprite
	CircleCollider* powerUpCircleCollider = new CircleCollider(10, this);
	this->setCollider(powerUpCircleCollider);
}

void PowerUp::draw()
{
	Actor::draw();
	getCollider()->draw();
}

void PowerUp::onCollision(Actor* other)
{
	//If player collides with power up sprite is deleted
	if (other->getName() == "Player")
		delete m_spriteComponent;
}
