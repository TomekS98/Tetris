#include "Level.h"

#include <string>

Level::Level()
{
	if (!_fontTxt.loadFromFile("fonts/font.ttf"))
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
	_levelmsg = std::to_string(_level);
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
	_levelmsg = std::to_string(_level);
	_timer.setDelayCausedByLevel();
}
void Level::increaseNumberOfDestroyedRows() 
{
	numberOfDestroyedRows++;
}

void Level::levelDraw(sf::RenderWindow &w)
{
	w.draw(_levelTxt);
}

int Level::getLevel() {
	return _level;
}

int Level::getNumberOfRowsDestroyed() {
	return numberOfDestroyedRows;
}
void Level::CheckIfItsTimeToIncreaseLevel(Timer & _timer)
{
	if (this->getLevel() != (this->getNumberOfRowsDestroyed() /3))
	{
		this->increaseLevel(_timer);
	}
}

std::string Level::getlevelmsg() {
	return _levelmsg;
}