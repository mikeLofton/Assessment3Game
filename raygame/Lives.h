#pragma once
#include "Actor.h"
class Sprite;

class Lives :
	public Actor
{
public:
	Lives(float x, float y, const char* name) : Actor(x, y, name){}
	~Lives();

	void start() override;
	

private:
	Sprite* m_spriteComponent;
};

