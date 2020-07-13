
#include "GameController.h"


GameController::GameController(BlocksGenerator blocksGenerator, PlayField playField)
{
	this->blocksGenerator = blocksGenerator;
	this->playField = playField;
	_hasLostGame = false;
	_canEnterHere = true;
}
void GameController::resetThePlayField()
{
	PlayField p =PlayField();
	this->playField = p;
}

void GameController::Tick(sf::RenderWindow * w, GameMusic& _gameMusic, Top5Scores & _top5, Menu& _menu)
{
	sf::Event e;
	float time = clockk.getElapsedTime().asSeconds();
	clockk.restart();
	this->getTimer().setTimer(time);
	
	if (_hasLostGame&& _canEnterHere)
	{
		_gameMusic.musicStop();
		this->getGameSound().gameOverSound();
		_top5.updateTheScores(this->getScoreboard());
		_canEnterHere = false;
		return;
	}

	if (playField.GetCompleteRowY() != -1)
	{
		playField.RemoveRow(playField.GetCompleteRowY());
		this->getGameSound().oneLineSound();
		this->getScoreboard().getLevel().increaseNumberOfDestroyedRows();
		if (this->getScoreboard().getLevel().CheckIfItsTimeToIncreaseLevel(this->getTimer()))
		{
			this->getGameSound().levelUpSound();
		}
		this->getScoreboard().updateScore(100);
		
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

	while (w->pollEvent(e)) {
		if (e.type == sf::Event::Closed)
			w->close();
		if (e.type == sf::Event::KeyPressed) {
			if (e.key.code == sf::Keyboard::Up)
			{
				currentBlock.Rotate();
			}
			if (e.key.code == sf::Keyboard::Down && !this->getTimer().checkIfItsSpeededUp())
			{
				this->getTimer().setSpeed(Speed::Fast, this->getTimer());

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
			else if (e.key.code == sf::Keyboard::R)
			{
				_gameMusic.musicStop();
				_gameMusic.changeTheStateOfPlayMusic(False);
				_menu.changeTheStateOfEnter(True);
				_menu.setChoicedItemIndex(2);
				for (int i = 0; i < 20; i++) {
					playField.RemoveRow(i);
				}
				this->getScoreboard().resetScore();
				this->getScoreboard().getLevel().resetLevel();
				this->getTimer().resetDelay();
				_hasLostGame = false;
				_canEnterHere = true;
			}
		}
	}
	
	
	if (this->getTimer().getTimer()> this->getTimer().getDelay() && currentBlock.CanMoveDown(playField))
	{
		if (this->getTimer().checkIfItsSpeededUp())
		{
			this->getTimer().setSpeed(Speed::Regular, this->getTimer());
		}
		currentBlock.MoveDown();
		this->getTimer().resetTimer();
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

