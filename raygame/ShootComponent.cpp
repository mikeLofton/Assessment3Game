#include "ShootComponent.h"
#include "Bullet.h"
#include "Engine.h"
#include "InputComponent.h"


void ShootComponent::start()
{
	m_inputComponent = dynamic_cast<InputComponent*>(getOwner()->getComponent("InputComponent"));
}

void ShootComponent::spawnBullet()
{
	if (RAYLIB_H::IsKeyPressed(RAYLIB_H::KEY_SPACE))
	{
		Bullet* bullet = new Bullet(getOwner()->getTransform()->getLocalPosition().x, getOwner()->getTransform()->getLocalPosition().y, getOwner()->getTransform()->getForward(), "bullet");
		bullet->getTransform()->setScale({ 50, 50 });

		Engine::getCurrentScene()->addActor(bullet);
	}
}
