#pragma once
#include <SFML/Graphics.hpp>
class Textures
{
	sf::Texture textureBase;
	sf::Sprite spriteBase;
public:
	Textures(const char* _filePath);
	sf::Sprite getSpriteOfTexture();
	void setPositionOfSprite(int X, int Y);
	void setTextureRectangle(int startX, int startY, int Y, int X);
	void Draw(sf::RenderWindow & w);
};

