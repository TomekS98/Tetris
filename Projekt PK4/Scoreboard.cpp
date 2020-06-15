#include "Scoreboard.h"
#include <string>

Scoreboard::Scoreboard() 
{
	if (!_fontTxt.loadFromFile("fonts/font.ttf"))
	{
		return;
	}
	sf::Color gray_color(211, 211, 211);
	_scoreTxt.setFont(_fontTxt);
	_scoreTxt.setString("0");
	_scoreTxt.setCharacterSize(64);
	_scoreTxt.setFillColor(gray_color);
	_scoreTxt.setPosition(370, 65);
	score = 0;
	_scoremsg = std::to_string(score);
 }

void Scoreboard::Draw(sf::RenderWindow &w)
{
	w.draw(_scoreTxt);
}

void Scoreboard::updateScore(int _score, Level level)
{
	int multiplierOfScore=level.getLevel()+1;
	score += multiplierOfScore*_score*0.11;
	_scoreTxt.setString(std::to_string(score));
	_scoremsg = std::to_string(score);
}

sf::Text Scoreboard::getScoreTxt() {
	return _scoreTxt;
}

std::string Scoreboard::getscoremsg() {
	return _scoremsg;
}
