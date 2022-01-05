#include "StartScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Sprite.h"
#include "MovementComponent.h"
#include "Transform2D.h"
#include "EnemySpawner.h"

void StartScene::start()
{
	Player* player = new Player(50, 500, "Player");
	player->getTransform()->setScale({ 50, 50 });

	/*Actor* test = new Actor(400, 500, "Test");*/

	/*Enemy* enemy = new Enemy(55, 50, "Enemy", player);
	enemy->getTransform()->setScale({ 50, 50 });*/

	EnemySpawner* spawner1 = new EnemySpawner(100, 5, "Spawner1");


	addActor(player);
	/*addActor(enemy);*/
	addActor(spawner1);
}
