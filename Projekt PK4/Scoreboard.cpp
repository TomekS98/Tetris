#include "Scoreboard.h"
#include <string>

Scoreboard::Scoreboard()
{
	if (!_fontTxt.loadFromFile(FONT_PATH1))
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
 }

void Scoreboard::Draw(sf::RenderWindow &w)
{
	w.draw(_scoreTxt);
}

void Scoreboard::updateScore(int _score)
{
	int multiplierOfScore=this->getLevel().getLevel() +1;
	score += multiplierOfScore*_score*0.11;
	_scoreTxt.setString(std::to_string(score));
}

sf::Text Scoreboard::getScoreTxt() {
	return _scoreTxt;
}

