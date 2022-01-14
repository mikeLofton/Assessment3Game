#include "GameManager.h"
#include "UIText.h"
#include "Engine.h"

int GameManager::enemyCount = 10;
int GameManager::lifeCount = 3;

void GameManager::start()
{
	Actor::start();
	m_winText = new UIText(450, 500, "Win Text", RAYWHITE, 50, "You Win");
	m_loseText = new UIText(450, 500, "Lose Text", RAYWHITE, 50, "You Lose");
}

void GameManager::update(float deltaTime)
{
	if (enemyCount <= 0)
		Engine::getCurrentScene()->addUIElement(m_winText);

	if (lifeCount <= 0)
		Engine::getCurrentScene()->addUIElement(m_loseText);
}
