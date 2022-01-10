#include "PlayerLife.h"
#include "Lives.h"
#include "Engine.h"
#include "Transform2D.h"


void PlayerLife::start()
{
	Component::start();

	life1 = new Lives(200, 975, "Life1");
	life1->getTransform()->setScale({ 90, 90 });

	life2 = new Lives(250, 975, "Life2");
	life2->getTransform()->setScale({ 90, 90 });

	life3 = new Lives(300, 975, "Life3");
	life3->getTransform()->setScale({ 90, 90 });

	Engine::getCurrentScene()->addActor(life1);
	Engine::getCurrentScene()->addActor(life2);
	Engine::getCurrentScene()->addActor(life3);
}

void PlayerLife::removeLife1()
{
	Engine::getCurrentScene()->removeActor(life1);
}

void PlayerLife::removeLife2()
{
	Engine::getCurrentScene()->removeActor(life2);
}

void PlayerLife::removeLife3()
{
	Engine::getCurrentScene()->removeActor(life3);
}