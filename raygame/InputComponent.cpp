#include "InputComponent.h"
#include "Bullet.h"
#include "Transform2D.h"
#include "Engine.h"

MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	float moveDirectionX = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_A) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_D);
	float moveDirectionY = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_W) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_S);

	//Returns
	return MathLibrary::Vector2(moveDirectionX, moveDirectionY);
}

void InputComponent::spawnBullet()
{
	if (RAYLIB_H::IsKeyPressed(RAYLIB_H::KEY_SPACE))
	{
		Bullet* bullet = new Bullet(getOwner()->getTransform()->getLocalPosition().x, getOwner()->getTransform()->getLocalPosition().y, getOwner()->getTransform()->getForward(), "bullet");
		bullet->getTransform()->setScale({ 50, 50 });
		
		Engine::getCurrentScene()->addActor(bullet);
	}
}

