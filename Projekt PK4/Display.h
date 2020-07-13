#pragma once

#include <SFML/Graphics.hpp>
#include "PlayField.h"
#include "Defines.h"
#include "BlocksGenerator.h"
#include "PlayField.h"
#include "GameController.h"
#include "GameMusic.h" 
#include "GameSounds.h"
#include "Menu.h"
#include "Textures.h"

class Display
{
	sf::RenderWindow window;
	Menu menu;
	Textures allTextures[NUMBER_OF_TEXTURES];
	GameController _gamecontroller;
	Top5Scores _top5;
	GameMusic gamemusicc;
public:
	Display();
	Display(Textures tab[],GameController &gameController);
	bool checkIfWindowIsOpen();
	void displayMenu();
	sf::RenderWindow * getWindow();
	void displayScores();
	void displayGame();
	Menu & getMenu() { return menu; }
	GameMusic &getGameMusic() { return gamemusicc; }
	Top5Scores &getTop5Scores() { return _top5; }
};
