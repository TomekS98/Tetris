#pragma once
#include <SFML/Graphics.hpp>
class Level
{
	int _level;
	sf::Text _levelTxt;
public:
	Level(sf::Font _font);
	Level(int desiredLevel, sf::Font _font);
	void increaseLevel();
	void levelDraw(sf::RenderWindow &w);
	int getLevel();
};

