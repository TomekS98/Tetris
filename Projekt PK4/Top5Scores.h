#pragma once
#include "Scoreboard.h"
#include "Bollean.h"
#include "Menu.h"
#include <fstream>
#include "Defines.h"

class Top5Scores
{
	sf::Font font;
	sf::Text scores[NUMBER_OF_SCORES];
	int scores_int[NUMBER_OF_SCORES];
	bool executeDisplayOfHighscore;

public:
	Top5Scores(float width, float height);
	void draw(sf::RenderWindow&window);
	void updateTheScores(Scoreboard _actualScore);
	void scoresWindowController(sf::RenderWindow &window, Menu & _menu);
	bool getTheStateOfDispayHighscores() { return executeDisplayOfHighscore; }
	void changeTheStateOfDisplayHigscores(Bollean varOfBollean);
};

