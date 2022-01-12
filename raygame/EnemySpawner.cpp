#include "EnemySpawner.h"
#include "Engine.h"
#include "Enemy.h"
#include "Transform2D.h"
#include "Player.h"


void EnemySpawner::start()
{
	Actor::start();

}

void EnemySpawner::update(float deltaTime)
{
	m_timeSinceLastSpawn += deltaTime;

	if (m_enemyTotal < 5 && m_timeSinceLastSpawn > m_spawnCooldown)
	{
		m_enemy = new Enemy(getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y, "Enemy", EnemySpawner::m_currentPlayer);
		m_enemy->getTransform()->setScale({ 50, 50 });

		Engine::getCurrentScene()->addActor(m_enemy);
		m_enemyTotal++;
		m_timeSinceLastSpawn = 0;
	}

	
}
