#pragma once
#include "Actor.h"
class SpawnComponent;

class EnemySpawner :
	public Actor
{
public:

	/*EnemySpawner(float x, float y, const char* name, Actor* enemy) : Actor(x, y, name) { m_currentEnemy = enemy; }*/
	EnemySpawner(float x, float y, const char* name) : Actor(x, y, name) {}
	~EnemySpawner();

	void start() override;
	void update(float deltaTime) override;

private:
	int m_enemyTotal = 0;
	float m_timeSinceLastSpawn;
	float m_spawnCooldown = 1;
	Actor* m_currentEnemy;
	SpawnComponent* m_spawnComponent;
};

