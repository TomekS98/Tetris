#pragma once

#include <SFML/Graphics.hpp>
#include "Level.h"
#include <string>

class Scoreboard
{
	int score;
	sf::Font _fontTxt;
	sf::Text _scoreTxt;
	std::string _scoremsg;
public:
	Scoreboard();
	void Draw(sf::RenderWindow &w);
	void updateScore(int score, Level level);
	sf::Text getScoreTxt();
	std::string getscoremsg();
	int getScoreAsInt() { return stoi(_scoremsg); }
	void resetScore() { score = 0; _scoremsg = std::to_string(score); _scoreTxt.setString(_scoremsg); }
};

