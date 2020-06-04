#pragma once

#include <SFML/Graphics.hpp>
#include "Level.h"

class Scoreboard
{
	int score;
	sf::Text _scoreTxt;

public:
	Scoreboard(sf::Font _font);
	void Draw(sf::RenderWindow &w);
	void updateScore(int score, Level level);
	sf::Text getScoreTxt();
};

