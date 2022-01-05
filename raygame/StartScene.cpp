#include "StartScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Sprite.h"
#include "MovementComponent.h"
#include "Transform2D.h"
#include "EnemySpawner.h"
#include "CircleCollider.h"
#include "PowerUp.h"

void StartScene::start()
{
	Player* player = new Player(50, 500, "Player");
	player->getTransform()->setScale({ 50, 50 });
	CircleCollider* playerCircleCollider = new CircleCollider(player);
	player->setCollider(playerCircleCollider);
	playerCircleCollider->setCollisionRadius(20);

	PowerUp* powerUp = new PowerUp(500, 500, "Power Up");
	powerUp->getTransform()->setScale({ 50, 50 });

	Enemy* enemy = new Enemy(55, 50, "Enemy", player);
	enemy->getTransform()->setScale({ 50, 50 });

	/*EnemySpawner* spawner1 = new EnemySpawner(100, 5, "Spawner1", enemy);*/

	addActor(powerUp);
	addActor(player);
	addActor(enemy);
	/*addActor(spawner1);*/
}
