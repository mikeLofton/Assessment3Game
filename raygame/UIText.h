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

	/// <param name="x">The text's x position in the world</param>
	/// <param name="y">The text's y position in the world</param>
	/// <param name="name">The UI element's name</param>
	/// <param name="color">The text color</param>
	/// <param name="fSize">The font size</param>
	/// <param name="textToWrite">The message to display</param>
	UIText(float x, float y, const char* name, Color color, int fSize, const char* textToWrite);

	/// <summary>
	/// Draws the text to the screen
	/// </summary>
	void draw() override;

};

