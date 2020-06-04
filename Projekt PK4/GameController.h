#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include "BlocksGenerator.h"
#include "Scoreboard.h"
#include "Timer.h"

class GameController
{
	Block currentBlock;
	PlayField playField;
	BlocksGenerator blocksGenerator;
	bool hasLostGame;
public:
	GameController();
	GameController(BlocksGenerator blocksGenerator, PlayField playField);
	void Tick(sf::Clock  &clock, Timer &Timer,sf::Event &e, sf::RenderWindow &w);
	Block GetCurrentBlock();
	PlayField GetPlayField();
	bool IsInGame();
};

