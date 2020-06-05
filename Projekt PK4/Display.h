#pragma once

#include <SFML/Graphics.hpp>
#include "PlayField.h"

class Display
{
	const int TILES_PIXEL_COUNT = 32;

	sf::Sprite tilesSprite;
	PlayField playField;
	sf::RenderWindow window;
public:
	Display(PlayField playField );
	void DisplayGame();
	bool CanDisplay();
};

