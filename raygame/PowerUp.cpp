#include "PowerUp.h"
#include "Bullet.h"
#include "Sprite.h"
#include "CircleCollider.h"
#include "Engine.h"
#include "Transform2D.h"
#include <iostream>
#include "Player.h"

void PowerUp::start()
{
	Actor::start();
	//Power up sprite
	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/Flameless.png")));

	//The power ups sprite
	CircleCollider* powerUpCircleCollider = new CircleCollider(10, this);
	this->setCollider(powerUpCircleCollider);
}

void PowerUp::draw()
{
	Actor::draw();
	//Draw Collider
	getCollider()->draw();
}
