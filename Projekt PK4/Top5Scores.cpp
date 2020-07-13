#include "Top5Scores.h"

Top5Scores::Top5Scores()
{
	if (!font.loadFromFile(FONT_PATH1))
	{
		return;
	}
	for (int i = 0; i < NUMBER_OF_SCORES; i++)
	{
		scores[i].setFont(font);
		scores[i].setFillColor(sf::Color::Blue);
		scores[i].setCharacterSize(64);
		scores[i].setPosition(sf::Vector2f(WIDTH1 / 3, 120 * (i+1)));
	}
	std::ifstream plik;
	plik.open(TOP5SCORES_PATH);
	if (!plik.good()) {
		return;
	}
	while (!plik.eof())
	{
		for (int i = 0; i < NUMBER_OF_SCORES; i++)
		{
			plik >> scores_int[i];
			
			scores[i].setString(std::to_string(scores_int[i]));
		}
	}
	plik.close();
	executeDisplayOfHighscore = false;
}


void Top5Scores::draw(sf::RenderWindow&window)
{
	for (int i = 0; i < NUMBER_OF_SCORES; i++)
	{
		window.draw(scores[i]);
	}
}

void Top5Scores::updateTheScores(Scoreboard _actualScore)
{
	std::ofstream plik;
	std::unique_ptr <int[]> tmpArrayOfScores(new int[NUMBER_OF_SCORES]);

	for (int i = 0; i < NUMBER_OF_SCORES; i++)
	{
		tmpArrayOfScores[i] = scores_int[i];
	}
	plik.open(TOP5SCORES_PATH);
	if(!plik.good())
	{
		return;
	}
	for (int i = 0; i < NUMBER_OF_SCORES; i++)
	{
		if (scores_int[i] < _actualScore.getScoreAsInt())
		{
			scores_int[i] = _actualScore.getScoreAsInt();
			scores[i].setString(std::to_string(scores_int[i]));
			for (int j = i; j < NUMBER_OF_SCORES-1; j++)
			{
				scores_int[j + 1] = tmpArrayOfScores[j];
				scores[j + 1].setString(std::to_string(scores_int[j + 1]));
			}
			break;
		}
	}

	for (int i = 0; i < NUMBER_OF_SCORES; i++)
	{
		plik << scores_int[i] << std::endl;
	}
	plik.close();
}

void Top5Scores::scoresWindowController(sf::RenderWindow &window, Menu & _menu) 
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::Return:
				executeDisplayOfHighscore = false;
				_menu.changeTheStateOfEnter(True);
				_menu.setChoicedItemIndex(2);
			}
			break;
		case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

void Top5Scores::changeTheStateOfDisplayHigscores(Bollean varOfBollean)
{
	switch (varOfBollean) {
	case True:
		executeDisplayOfHighscore = true;
		break;
	case False:
		executeDisplayOfHighscore = false;
		break;
	default:
		break;
	}
}