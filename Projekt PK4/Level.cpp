#include "Level.h"

#include <string>

Level::Level()
{
	if (!_fontTxt.loadFromFile(FONT_PATH1))
	{
		return;
	}
	sf::Color gray_color(211, 211, 211);
	_levelTxt.setFont(_fontTxt);
	_levelTxt.setString("1");
	_levelTxt.setCharacterSize(64);
	_levelTxt.setFillColor(gray_color);
	_levelTxt.setPosition(420, 185);
	_level = 1;
	numberOfDestroyedRows = 0;
}
Level::Level(int desiredLevel, sf::Font _font)
{
	_levelTxt.setFont(_font);
	_levelTxt.setString(std::to_string(desiredLevel));
	_levelTxt.setCharacterSize(64);
	_levelTxt.setFillColor(sf::Color::White);
	_levelTxt.setPosition(380, 200);
	_level = desiredLevel;
}
void Level::increaseLevel(Timer & _timer)
{
	_level++;
	_levelTxt.setString(std::to_string(_level));
	_timer.setDelayCausedByLevel();
}
void Level::increaseNumberOfDestroyedRows() 
{
	this->numberOfDestroyedRows++;
}

void Level::levelDraw(sf::RenderWindow &w)
{
	w.draw(_levelTxt);
}

int Level::getLevel() {
	return this->_level;
}

int Level::getNumberOfRowsDestroyed() {
	return numberOfDestroyedRows;
}
bool Level::CheckIfItsTimeToIncreaseLevel(Timer & _timer)
{
	if (this->getLevel()-1 != (this->getNumberOfRowsDestroyed() / NUMBER_OF_DESTROYED_LINES_REQUIRED_TO_LEVEL_UP))
	{
		this->increaseLevel(_timer);
		return true;
	}
	return false;
}

