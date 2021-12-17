#pragma once
#include "Component.h"
#include <Vector2.h>
class InputComponent;

class ShootComponent :
	public Component
{
public:
	void start() override;
	void spawnBullet();
private:
	MathLibrary::Vector2 m_velocity;
	InputComponent* m_inputComponent;

};

