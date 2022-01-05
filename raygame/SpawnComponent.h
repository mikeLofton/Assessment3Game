#pragma once
#include "Component.h"
class Enemy;

class SpawnComponent :
	public Component
{
public:
	SpawnComponent(const char* name = "SpawnComponent") : Component::Component(name) {}
	void spawnEnemyShips();

private:
	int m_enemyTotal = 0;
	Enemy* m_enemy;
};

