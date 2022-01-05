#include "EnemySpawner.h"
#include "Engine.h"

void EnemySpawner::update(float deltaTime)
{
	if (m_enemyTotal < 20)
	{
		Engine::getCurrentScene()->addActor(m_currentEnemy);
		m_enemyTotal++;
	}
}
