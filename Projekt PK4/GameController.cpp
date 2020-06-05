
#include "GameController.h"


GameController::GameController()
{
	_hasLostGame = false;
	_canEnterHere = true;
}

GameController::GameController(BlocksGenerator blocksGenerator, PlayField playField)
{
	this->blocksGenerator = blocksGenerator;
	this->playField = playField;
	_hasLostGame = false;
}

void GameController::Tick(sf::Clock &clock,Timer &timer, sf::Event &e, sf::RenderWindow& w,GameMusic& _gameMusic,GameSounds &_gameSounds,TextPoppingUp& _txtmsg, Level & _level,Scoreboard & _scoreboard)
{
	float time = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer.setTimer(time);
	
	if (_hasLostGame&& _canEnterHere)
	{
		//_txtmsg.setText("GAME OVER");
		//_txtmsg.textDraw(w);
		_gameMusic.musicStop();
		_gameSounds.gameOverSound();
		_canEnterHere = false;
		return;
	}

	if (playField.GetCompleteRowY() != -1)
	{
		playField.RemoveRow(playField.GetCompleteRowY());
		_gameSounds.oneLineSound();
		_level.increaseNumberOfDestroyedRows();
		_level.CheckIfItsTimeToIncreaseLevel(timer);
		_scoreboard.updateScore(100,_level);
	}

	if (!currentBlock.CanMoveDown(playField)&& _canEnterHere)
	{
		for (int i = 0; i < 4; i++)
		{
			playField.AddTile(currentBlock.GetTile(i));
		}

		currentBlock = blocksGenerator.GenerateBlock();

		if (!currentBlock.CanMoveDown(playField))
		{
			_hasLostGame = true;
		}
	}
	
	while (w.pollEvent(e)) {
		if (e.type == sf::Event::Closed)
			w.close();
		if (e.type == sf::Event::KeyPressed) {
			if (e.key.code == sf::Keyboard::Up)
			{
				currentBlock.Rotate();
			}
			if (e.key.code == sf::Keyboard::Down && !timer.checkIfItsSpeededUp())
			{
				timer.setSpeed(Speed::Fast,timer);
				//timer.setDelayCausedByKeyDown();

			}
			else if (e.key.code == sf::Keyboard::Left && currentBlock.CanMoveHorizontally(playField, Direction::Left))
			{
				currentBlock.MoveHorizontally(Direction::Left);

			}
			else if (e.key.code == sf::Keyboard::Right && currentBlock.CanMoveHorizontally(playField, Direction::Right))
			{
				currentBlock.MoveHorizontally(Direction::Right);

			}
			else if (e.key.code == sf::Keyboard::P)
			{
				_gameMusic.volumeChangeOfTheMusic(VolumeChange::Higher);
			}
			else if (e.key.code == sf::Keyboard::O)
			{
				_gameMusic.volumeChangeOfTheMusic(VolumeChange::Lower);
			}
		}
	}
	
	
	if (timer.getTimer()>timer.getDelay() && currentBlock.CanMoveDown(playField))
	{
		if (timer.checkIfItsSpeededUp())
		{
			timer.setSpeed(Speed::Regular, timer);
			//timer.resetDelayAfterKeyDown();
		}
		currentBlock.MoveDown();
		timer.resetTimer();
	}
}

Block GameController::GetCurrentBlock()
{
	return currentBlock;
}

bool GameController::IsInGame()
{
	return !_hasLostGame;
}

PlayField GameController::GetPlayField()
{
	return playField;
}