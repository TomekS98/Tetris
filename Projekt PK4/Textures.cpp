
#include "Textures.h"

Textures::Textures()
{
}
Textures::Textures(const char *_filePath)
{
	if (!textureBase.loadFromFile(_filePath))
	{
		return;
	}
	spriteBase = sf::Sprite(textureBase);
}
sf::Sprite Textures::getSpriteOfTexture()
{
	return spriteBase;
}

void Textures::setPositionOfSprite(int X, int Y)
{
	spriteBase.setPosition(X, Y);
}

void Textures::setTextureRectangle(int startX, int startY, int Y, int X)
{
	spriteBase.setTextureRect(sf::IntRect(startX, startY, X, Y));
}
void Textures::Draw(sf::RenderWindow &w)
{
	w.draw(spriteBase);
}

