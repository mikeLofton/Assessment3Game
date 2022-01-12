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
#include "PowerUpSpawner.h"

void StartScene::start()
{
	//Player
	Player* player = new Player(50, 500, "Player");
	player->getTransform()->setScale({ 50, 50 });
	//Player colliderddd
	CircleCollider* playerCircleCollider = new CircleCollider(player);
	player->setCollider(playerCircleCollider);
	playerCircleCollider->setCollisionRadius(20);

	//Power up
	PowerUp* powerUp = new PowerUp(100, 100, "Power Up");
	powerUp->getTransform()->setScale({ 50, 50 });

	PowerUp* powerUp2 = new PowerUp(600, 900, "Power Up 2");
	powerUp2->getTransform()->setScale({ 50, 50 });

	//Enemy Spawners
	EnemySpawner* spawner1 = new EnemySpawner(55, 0, "Spawner1", player);
	EnemySpawner* spawner2 = new EnemySpawner(600, 1000, "Spawner2", player);

	PowerUpSpawner* powerUpSpawner1 = new PowerUpSpawner(500, 500, "Power Up", 20);
	PowerUpSpawner* powerUpSpawner2 = new PowerUpSpawner(500, 200, "Power Up 2", 10);

	//Life UI text
	UIText* lifeText = new UIText(10, 950, "Life Text", RAYWHITE, 50, "Lives ");

	
	addActor(powerUp2);
	addActor(powerUp);
	addActor(player);
	addActor(spawner1);
	addActor(spawner2);
	addUIElement(lifeText);
	addActor(powerUpSpawner2);
	addActor(powerUpSpawner1);
}
