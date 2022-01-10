#pragma once
#include "Actor.h"
#include <raylib.h>

class UIText :
	public Actor
{
public:
	const char* text;
	float textXPosition;
	float textYPosition;
	int fontSize;
	Font font;
	Color fontColor;

	UIText(float x, float y, const char* name, Color color, int fSize, const char* textToWrite);

	void draw() override;

};

