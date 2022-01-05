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
	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/bullet.png")));
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

	if (other->getName() == "Player")
	{
		Engine::getCurrentScene()->removeActor(this);
		delete m_spriteComponent;
	}
}
