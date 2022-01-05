#include "EnemySpawner.h"
#include "Engine.h"
#include "SpawnComponent.h"
#include "Enemy.h"
#include "Transform2D.h"

void EnemySpawner::start()
{
	m_spawnComponent = dynamic_cast<SpawnComponent*>(addComponent(new SpawnComponent()));
}

void EnemySpawner::update(float deltaTime)
{
	Actor* test = new Actor(400, 500, "Test");
	m_currentEnemy = new Enemy(1, 1, "EnemyTest", test);
	m_currentEnemy->getTransform()->setScale({ 50, 50 });

	m_timeSinceLastSpawn += deltaTime;

	if (m_enemyTotal < 2 && m_timeSinceLastSpawn > m_spawnCooldown)
	{
		Engine::getCurrentScene()->addActor(m_currentEnemy);
		m_enemyTotal++;
		m_timeSinceLastSpawn = 0;
	}
}
