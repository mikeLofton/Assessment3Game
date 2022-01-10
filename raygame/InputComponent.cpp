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
	//If player presses the spacebar returns true
	if (IsKeyPressed(m_action1Key))
		return true;
	
}

