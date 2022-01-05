#pragma once
#include "Actor.h"
class Enemy;

class EnemySpawner :
	public Actor
{
public:

	EnemySpawner(float x, float y, const char* name, Actor* enemy) : Actor(x, y, name) { m_currentEnemy = enemy; }
	~EnemySpawner();

	void update(float deltaTime) override;

private:
	int m_enemyTotal = 0;
	Actor* m_currentEnemy;
};

