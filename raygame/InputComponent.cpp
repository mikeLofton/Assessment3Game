#include "InputComponent.h"
#include "Bullet.h"
#include "Transform2D.h"
#include "Engine.h"
#include <iostream>
#include "Bullet.h"

MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	//Player movement
	float moveDirectionX = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_A) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_D);
	float moveDirectionY = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_W) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_S);

	//Returns direction the player is moving
	return MathLibrary::Vector2(moveDirectionX, moveDirectionY);
}

bool InputComponent::checkActionKey()
{
	if (IsKeyPressed(m_action1Key))
	{
		std::cout << "Bullet Created" << std::endl;
		return true;
	}
	
}

//MathLibrary::Vector2 InputComponent::shootAction()
//{
//
//	float bulletDirectionX = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_LEFT) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_RIGHT);
//	float bulletDirectionY = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_UP) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_DOWN);
//
//	if (bulletDirectionX != 0 || bulletDirectionY != 0)
//	{
//		Bullet* bullet = new Bullet(getOwner()->getTransform()->getWorldPosition().x, getOwner()->getTransform()->getWorldPosition().y, "bullet");
//		bullet->getTransform()->setScale({ 50, 50 });
//		
//		Engine::getCurrentScene()->addActor(bullet);
//	}
//	if (bulletDirectionY < 0)
//		std::cout << "Test bullet" << std::endl;
//
//	return MathLibrary::Vector2(bulletDirectionX, bulletDirectionY);
//}

