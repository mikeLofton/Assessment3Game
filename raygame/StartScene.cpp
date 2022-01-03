#include "StartScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Sprite.h"
#include "MovementComponent.h"
#include "Transform2D.h"

void StartScene::start()
{
	Player* player = new Player(50, 500, "Player");
	player->getTransform()->setScale({ 50, 50 });

	Enemy* enemy = new Enemy(55, 50, "Enemy", player);
	enemy->getTransform()->setScale({ 50, 50 });

	addActor(player);
	addActor(enemy);
}
