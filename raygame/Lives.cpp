#include "Lives.h"
#include "Sprite.h"

void Lives::start()
{
	Actor::start();
	//Adds the sprite component
	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/star.png")));

	
}
