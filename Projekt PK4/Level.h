#pragma once
#include <SFML/Graphics.hpp>
#include "PlayField.h"
#include "Timer.h"
class Level
{
	int _level;
	sf::Text _levelTxt;
	sf::Font _fontTxt;
	int numberOfDestroyedRows;
	std::string _levelmsg;
public:
	Level();
	Level(int desiredLevel, sf::Font _font);
	void increaseLevel(Timer & _timer);
	void increaseNumberOfDestroyedRows();
	void levelDraw(sf::RenderWindow &w);
	int getLevel();
	int getNumberOfRowsDestroyed();
	void CheckIfItsTimeToIncreaseLevel(Timer&_timer);
	std::string getlevelmsg();
	void resetLevel() { _level = 0; numberOfDestroyedRows = 0; _levelmsg = std::to_string(_level); _levelTxt.setString(_levelmsg); }
};

