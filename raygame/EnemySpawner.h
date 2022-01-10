#pragma once
#include "Actor.h"
class Player;
class GameWin;

class EnemySpawner :
	public Actor
{
public:

	EnemySpawner(float x, float y, const char* name, Player* player) : Actor(x, y, name) { m_currentPlayer = player; }
	~EnemySpawner();

	void start() override;
	void update(float deltaTime) override;

private:
	int m_enemyTotal = 0;
	float m_timeSinceLastSpawn;
	float m_spawnCooldown = 1;
	Actor* m_enemy;
	Player* m_currentPlayer;
	GameWin* m_gameWinComponent;
};

