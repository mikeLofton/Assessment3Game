#include "GameWin.h"
#include "UIText.h"
#include "Engine.h"

void GameWin::start()
{
	winText = new UIText(300, 500, "WinText", RAYWHITE, 50, "YOU WIN!!!");
}

void GameWin::displayWinText()
{
	Engine::getCurrentScene()->addUIElement(winText);
}
