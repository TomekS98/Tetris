#pragma once
#include <SFML/Graphics.hpp>
#include "PlayField.h"
#include "Timer.h"
class Level
{
	int _level;
	sf::Text _levelTxt;
	int numberOfDestroyedRows;
	std::string _levelmsg;
public:
	Level(sf::Font _font);
	Level(int desiredLevel, sf::Font _font);
	void increaseLevel(Timer & _timer);
	void increaseNumberOfDestroyedRows();
	void levelDraw(sf::RenderWindow &w);
	int getLevel();
	int getNumberOfRowsDestroyed();
	void CheckIfItsTimeToIncreaseLevel(Timer&_timer);
	std::string getlevelmsg();
};

