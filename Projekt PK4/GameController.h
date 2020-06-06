#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include "BlocksGenerator.h"
#include "Scoreboard.h"
#include "Timer.h"
#include "GameMusic.h"
#include "GameSounds.h"
#include "TextPoppingUp.h"
#include "Level.h"
#include "Top5Scores.h"
class GameController
{
	Block currentBlock;
	PlayField playField;
	BlocksGenerator blocksGenerator;
	bool _hasLostGame;
	bool _canEnterHere;
public:
	GameController();
	GameController(BlocksGenerator blocksGenerator, PlayField playField);
	void Tick(sf::Clock  &clock, Timer &Timer, sf::Event &e, sf::RenderWindow &w, GameMusic & _gameMusic, GameSounds &_gameSounds, TextPoppingUp& _txtmsg, Level & _level,Scoreboard & _scoreboard,Top5Scores& _top5,Menu&_menu);
	Block GetCurrentBlock();
	PlayField GetPlayField();
	bool IsInGame();
};

