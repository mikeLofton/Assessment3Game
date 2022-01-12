#pragma once
#include "Actor.h"
class Player;

class EnemySpawner :
	public Actor
{
public:

	/// <param name="x">The spawner's x position in the world</param>
	/// <param name="y">The spawner's y position in the world</param>
	/// <param name="name">The spawner's name</param>
	/// <param name="player">The player that the spawned enemys target</param>
	EnemySpawner(float x, float y, const char* name, Player* player) : Actor(x, y, name) { m_currentPlayer = player; }

	//Destructor
	~EnemySpawner();

	/// <summary>
	/// Handles the spawning of enemies
	/// </summary>
	/// <param name="deltaTime">The time between each frame</param>
	void update(float deltaTime) override;

private:
	int m_enemyTotal = 0;
	float m_timeSinceLastSpawn;
	float m_spawnCooldown = 2;
	Actor* m_enemy;
	Player* m_currentPlayer;
};

