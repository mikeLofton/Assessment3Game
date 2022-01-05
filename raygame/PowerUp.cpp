#include "PowerUp.h"
#include "Bullet.h"
#include "Sprite.h"
#include "CircleCollider.h"

void PowerUp::start()
{
	Actor::start();
	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/bullet.png")));

	CircleCollider* powerUpCircleCollider = new CircleCollider(10, this);
	this->setCollider(powerUpCircleCollider);
}

void PowerUp::draw()
{
	getCollider()->draw();
}

void PowerUp::onColision(Actor* other)
{
	if (other->getName() == "Player")
	{

	}
}
