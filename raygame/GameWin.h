#pragma once
#include "Component.h"
class UIText;

class GameWin :
	public Component
{
public:

	GameWin(const char* name = "GameWin") : Component::Component(name) {}

	void start() override;
	void displayWinText();

private:
	UIText* winText;

};

