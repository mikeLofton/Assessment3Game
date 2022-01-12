#pragma once
#include "Actor.h"
class Sprite;

class Lives :
	public Actor
{
public:
	/// <summary>
	/// This class just gives lives a sprite
	/// </summary>
	Lives(float x, float y, const char* name) : Actor(x, y, name){}

	//Destructor
	~Lives();

	/// <summary>
	/// Called at game start
	/// </summary>
	void start() override;
	

private:
	Sprite* m_spriteComponent;
};

