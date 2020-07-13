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
	Timer timerr;
	GameSounds gameSounds;
	Scoreboard scoreboardd;
	sf::Clock clockk;
	bool _hasLostGame;
	bool _canEnterHere;
public:
	GameController() {}
	GameController(BlocksGenerator blocksGenerator, PlayField playField);
	void Tick(sf::RenderWindow * w, GameMusic & _gameMusic ,Top5Scores& _top5,Menu&_menu);
	Block GetCurrentBlock();
	PlayField GetPlayField();
	bool IsInGame();
	void resetThePlayField();
	Timer & getTimer() { return timerr; }
	GameSounds & getGameSound() { return gameSounds; }
	Scoreboard & getScoreboard() { return scoreboardd; }
};

