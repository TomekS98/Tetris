#include "Scoreboard.h"
#include <string>

Scoreboard::Scoreboard(sf::Font _font) 
{
	_scoreTxt.setFont(_font);
	_scoreTxt.setString("0");
	_scoreTxt.setCharacterSize(64);
	_scoreTxt.setFillColor(sf::Color::White);
	_scoreTxt.setPosition(350, 100);
	score = 0;
 }

void Scoreboard::Draw(sf::RenderWindow &w)
{
	w.draw(_scoreTxt);
}

void Scoreboard::updateScore(int _score, Level level)
{
	int multiplierOfScore=level.getLevel();
	score = multiplierOfScore*_score*0.11;
	_scoreTxt.setString(std::to_string(score));
}

sf::Text Scoreboard::getScoreTxt() {
	return _scoreTxt;
}