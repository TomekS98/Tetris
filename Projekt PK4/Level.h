#pragma once
#include <SFML/Graphics.hpp>
#include "PlayField.h"
#include "Timer.h"
#include "Defines.h"
class Level
{
	int _level;
	sf::Text _levelTxt;
	sf::Font _fontTxt;
	int numberOfDestroyedRows;
public:
	Level();
	Level(int desiredLevel, sf::Font _font);
	void increaseLevel(Timer & _timer);
	void increaseNumberOfDestroyedRows();
	void levelDraw(sf::RenderWindow &w);
	int getLevel();
	int getNumberOfRowsDestroyed();
	bool CheckIfItsTimeToIncreaseLevel(Timer&_timer);
	void resetLevel() { _level = 0; numberOfDestroyedRows = 0; _levelTxt.setString(std::to_string(_level)); }

};

