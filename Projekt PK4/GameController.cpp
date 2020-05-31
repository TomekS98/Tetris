
#include "GameController.h"


GameController::GameController()
{
	hasLostGame = false;
}

GameController::GameController(BlocksGenerator blocksGenerator, PlayField playField)
{
	this->blocksGenerator = blocksGenerator;
	this->playField = playField;


	hasLostGame = false;
}

void GameController::Tick(sf::Clock &clock, float &timer, float &delay, sf::Event &e, sf::RenderWindow& w)
{
	float time = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer += time;

	if (hasLostGame)
	{
		return;
	}

	if (playField.GetCompleteRowY() != -1)
	{
		playField.RemoveRow(playField.GetCompleteRowY());
	}

	if (!currentBlock.CanMoveDown(playField))
	{
		for (int i = 0; i < 4; i++)
		{
			playField.AddTile(currentBlock.GetTile(i));
		}

		currentBlock = blocksGenerator.GenerateBlock();

		if (!currentBlock.CanMoveDown(playField))
		{
			hasLostGame = true;
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
			if (e.key.code == sf::Keyboard::Down)
			{
				delay = 0.3;
			}
			else if (e.key.code == sf::Keyboard::Left && currentBlock.CanMoveHorizontally(playField, Direction::Left))
			{
				currentBlock.MoveHorizontally(Direction::Left);

			}
			else if (e.key.code == sf::Keyboard::Right && currentBlock.CanMoveHorizontally(playField, Direction::Right))
			{
				currentBlock.MoveHorizontally(Direction::Right);

			}
		}
	}
	
	if (timer>delay && currentBlock.CanMoveDown(playField))
	{
		currentBlock.MoveDown();
		timer = 0;
	}
}

Block GameController::GetCurrentBlock()
{
	return currentBlock;
}

bool GameController::IsInGame()
{
	return !hasLostGame;
}

PlayField GameController::GetPlayField()
{
	return playField;
}