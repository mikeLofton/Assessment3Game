#include "UIText.h"
#include "Transform2D.h"

UIText::UIText(float x, float y, const char* name, Color color, int fSize, const char* textToWrite) : Actor(x, y, name) 
{
	textXPosition = x;
	textYPosition = y;
	text = textToWrite;
	font = RAYLIB_H::LoadFont("resources/fonts/alagard.png");
	fontSize = fSize;
	fontColor = color;
}

void UIText::draw()
{
	DrawText(text, textXPosition, textYPosition, fontSize, fontColor);
}
