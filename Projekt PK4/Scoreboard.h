#pragma once

#include <SFML/Graphics.hpp>
#include "Level.h"
#include <string>

class Scoreboard
{
	int score;
	sf::Font _fontTxt;
	sf::Text _scoreTxt;
	Level level;
public:
	Scoreboard();
	void Draw(sf::RenderWindow &w);
	void updateScore(int score);
	sf::Text getScoreTxt();
	void resetScore() { score = 0; _scoreTxt.setString(std::to_string(score)); }
	int getScoreAsInt() { return score; }
	Level & getLevel() { return level;  }
};

