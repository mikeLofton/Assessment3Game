#include "GameManager.h"
#include "Engine.h"
#include "UIText.h"
#include "Lives.h"
#include "Transform2D.h"

void GameManager::start()
{
	Actor::start();
	Lives* life1 = new Lives(200, 975, "Life1");
	life1->getTransform()->setScale({ 90, 90 });

	Lives* life2 = new Lives(250, 975, "Life2");
	life2->getTransform()->setScale({ 90, 90 });

	Lives* life3 = new Lives(300, 975, "Life3");
	life3->getTransform()->setScale({ 90, 90 });

	Engine::getCurrentScene()->addActor(life1);
	Engine::getCurrentScene()->addActor(life2);
	Engine::getCurrentScene()->addActor(life3);

}

void GameManager::update(float deltaTime)
{

}

