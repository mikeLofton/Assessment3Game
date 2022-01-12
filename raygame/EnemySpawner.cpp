#include "EnemySpawner.h"
#include "Engine.h"
#include "Enemy.h"
#include "Transform2D.h"
#include "Player.h"


void EnemySpawner::update(float deltaTime)
{
	m_timeSinceLastSpawn += deltaTime;

	//If the total enemy's spawned is less than 5 and the time since the last enemy spawned is greater than the cooldown...
	if (m_enemyTotal < 5 && m_timeSinceLastSpawn > m_spawnCooldown)
	{
		//Create enemy
		m_enemy = new Enemy(getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y, "Enemy", EnemySpawner::m_currentPlayer);
		m_enemy->getTransform()->setScale({ 50, 50 });
		//Add enemy to the scene
		Engine::getCurrentScene()->addActor(m_enemy);
		//Decrement enemy total
		m_enemyTotal++;
		//Set last spawn to 0
		m_timeSinceLastSpawn = 0;
	}
}
