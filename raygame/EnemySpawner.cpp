#include "EnemySpawner.h"
#include "Engine.h"
#include "SpawnComponent.h"
#include "Enemy.h"
#include "Transform2D.h"
#include "Player.h"

void EnemySpawner::update(float deltaTime)
{
	m_timeSinceLastSpawn += deltaTime;

	if (m_enemyTotal < 3 && m_timeSinceLastSpawn > m_spawnCooldown)
	{
		m_enemy = new Enemy(55, 50, "Enemy", EnemySpawner::m_currentPlayer);
		m_enemy->getTransform()->setScale({ 50, 50 });

		Engine::getCurrentScene()->addActor(m_enemy);
		m_enemyTotal++;
		m_timeSinceLastSpawn = 0;
	}
}
