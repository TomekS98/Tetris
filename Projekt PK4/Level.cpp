#include "Level.h"
#include <string>

Level::Level(sf::Font _font)
{
	_levelTxt.setFont(_font);
	_levelTxt.setString("0");
	_levelTxt.setCharacterSize(64);
	_levelTxt.setFillColor(sf::Color::White);
	_levelTxt.setPosition(350, 100);
	_level = 0;
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
void Level::increaseLevel()
{
	_level++;
}
void Level::levelDraw(sf::RenderWindow &w)
{
	w.draw(_levelTxt);
}

int Level::getLevel() {
	return _level;
}
