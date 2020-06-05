#include "Display.h"

Display::Display(PlayField playField)
{
	this->playField = playField;
	sf::VideoMode VMode(480, 720, 32);
	window.create(VMode, "tetris", sf::Style::Close);
	sf::Texture tilesTexture;
	tilesTexture.loadFromFile("images/tiles.png");
	tilesSprite = sf::Sprite(tilesTexture);
	tilesSprite.setTextureRect(sf::IntRect(0, 0, TILES_PIXEL_COUNT, TILES_PIXEL_COUNT));
}

void Display::DisplayGame()
{
	window.clear(sf::Color::Black);

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (!playField.IsPositionOccupied(i, j))
			{
				continue;
			}
	
			Tile tile = playField.GetTile(i, j);
			tilesSprite.setTextureRect(sf::IntRect(tile.GetColor() * 32, 0, TILES_PIXEL_COUNT, TILES_PIXEL_COUNT));
			tilesSprite.setPosition(tile.GetX() * TILES_PIXEL_COUNT, tile.GetY() * TILES_PIXEL_COUNT);
			window.draw(tilesSprite);
		}
	}

	window.display();
}

bool Display::CanDisplay()
{
	return window.isOpen();
}
