#pragma once
#include "Actor.h"
class Player;

class PowerUpSpawner :
	public Actor
{
public:
	PowerUpSpawner(float x, float y, const char* name, float spawnCoolDown) : Actor(x, y, name) { m_spawnCoolDown = spawnCoolDown; }
	~PowerUpSpawner() {}

	void update(float deltaTime) override;

private:
	int m_powerUpTotal = 0;
	float m_timeSinceLastSpawn;
	float m_spawnCoolDown;
	Actor* m_powerUp;
};
