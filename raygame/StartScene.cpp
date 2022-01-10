#include "StartScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Sprite.h"
#include "MovementComponent.h"
#include "Transform2D.h"
#include "EnemySpawner.h"
#include "CircleCollider.h"
#include "PowerUp.h"
#include "UIText.h"

void StartScene::start()
{
	//Player
	Player* player = new Player(50, 500, "Player");
	player->getTransform()->setScale({ 50, 50 });
	//Player collider
	CircleCollider* playerCircleCollider = new CircleCollider(player);
	player->setCollider(playerCircleCollider);
	playerCircleCollider->setCollisionRadius(20);

	//Power up
	PowerUp* powerUp = new PowerUp(500, 500, "Power Up");
	powerUp->getTransform()->setScale({ 50, 50 });

	PowerUp* powerUp2 = new PowerUp(500, 700, "Power Up 2");
	powerUp2->getTransform()->setScale({ 50, 50 });


	/*Actor* test = new Actor(400, 500, "Test");*/

	/*Enemy* enemy = new Enemy(55, 50, "Enemy", player);
	enemy->getTransform()->setScale({ 50, 50 });*/

	EnemySpawner* spawner1 = new EnemySpawner(100, 5, "Spawner1", player);

	UIText* lifeText = new UIText(10, 950, "Life Text", RAYWHITE, 50, "Lives ");

	addActor(powerUp2);
	addActor(powerUp);
	addActor(player);
	addActor(spawner1);
	addUIElement(lifeText);

}
