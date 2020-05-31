#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include "BlocksGenerator.h"

class GameController
{
	Block currentBlock;
	PlayField playField;
	BlocksGenerator blocksGenerator;
	bool hasLostGame;
public:
	GameController();
	GameController(BlocksGenerator blocksGenerator, PlayField playField);
	void Tick(sf::Clock  &clock, float  &timer, float & delay,sf::Event &e, sf::RenderWindow &w);
	Block GetCurrentBlock();
	PlayField GetPlayField();
	bool IsInGame();
};

