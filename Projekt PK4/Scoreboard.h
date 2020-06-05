#pragma once

#include <SFML/Graphics.hpp>
#include "Level.h"
#include <string>

class Scoreboard
{
	int score;
	sf::Text _scoreTxt;
	std::string _scoremsg;

public:
	Scoreboard(sf::Font _font);
	void Draw(sf::RenderWindow &w);
	void updateScore(int score, Level level);
	sf::Text getScoreTxt();
	std::string getscoremsg();
};

