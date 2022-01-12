#include "PowerUpSpawner.h"
#include "PowerUp.h"
#include "Transform2D.h"
#include "Engine.h"

void PowerUpSpawner::update(float deltaTime)
{
	m_timeSinceLastSpawn += deltaTime;

	if (m_powerUpTotal < 5 && m_timeSinceLastSpawn > m_spawnCoolDown)
	{
		m_powerUp = new PowerUp(getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y, "Power Up");
		m_powerUp = new PowerUp(500, 200, "Power Up 2");
		m_powerUp->getTransform()->setScale({ 50, 50 });
		Engine::getCurrentScene()->addActor(m_powerUp);
		m_powerUpTotal++;
		m_timeSinceLastSpawn = 0;
	}
}
