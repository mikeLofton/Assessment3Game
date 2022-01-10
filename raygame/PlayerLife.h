#pragma once
#include "Component.h"
class Lives;

class PlayerLife :
	public Component
{
public:
	PlayerLife(const char* name = "Player") : Component::Component(name) {}
	void start() override;
	void removeLife1();
	void removeLife2();
	void removeLife3();
private:
	Lives* life1;
	Lives* life2;
	Lives* life3;
};

