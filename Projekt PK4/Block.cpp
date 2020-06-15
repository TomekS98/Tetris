#include "Block.h"

Block::Block()
{
}

Block::Block(Tile tiles[4])
{
	for (int i = 0; i < 4; i++)
	{
		this->tiles[i] = tiles[i];
	}
}

bool Block::CanMoveDown(PlayField playField)
{
	for (int i = 0; i < 4; i++)
	{
		if (playField.IsPositionOccupied(tiles[i].GetX(), tiles[i].GetY() + 1))
		{
			return false;
		}

		if (tiles[i].GetY() == HEIGHT - 1)
		{
			return false;
		}
	}

	return true;
}

void Block::MoveDown()
{
	for (int i = 0 ; i < 4; i++)
	{
		tiles[i].Move(0, 1);
	}
}

void Block::Rotate()
{
	bool notInArea = false;
	int a = 0, b = 0;
	int TileX = tiles[1].GetX();
	int TileY = tiles[1].GetY();
	int tabNewX[4], tabNewY[4];
	for (int i = 0; i < 4; i++)
	{
		int xDistance = tiles[i].GetY() - TileY;
		int yDistance = tiles[i].GetX() - TileX;
		tabNewX[i] = TileX - xDistance;
		tabNewY[i] = TileY + yDistance;
		if (tabNewX[i] < 0 || tabNewX[i]>10) notInArea = true;
	}
	while (notInArea) {
		for (int i = 0; i < 4; i++) {
			if (tabNewX[i] < 0) {
				for (int i = 0; i < 4; i++)
				{
					tabNewX[i]++;
					notInArea = false;
				}
			}
			else if (tabNewX[i] >= 10) {
				for (int i = 0; i < 4; i++)
				{
					tabNewX[i]-=3;
					notInArea = false;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		tiles[i].Set(tabNewX[i], tabNewY[i]);
	}
}

bool Block::CanMoveHorizontally(PlayField playField, Direction moveDirection)
{
	switch (moveDirection)
	{
	case Direction::Left:
		for (int i = 0; i < 4; i++)
		{
			if (tiles[i].GetX() - 1 < 0 || playField.IsPositionOccupied(tiles[i].GetX() - 1, tiles[i].GetY()))
			{
				return false;
			}
		}
		break;
	case Direction::Right:
		for (int i = 0; i < 4; i++)
		{
			if (tiles[i].GetX() + 1 >= WIDTH || playField.IsPositionOccupied(tiles[i].GetX() + 1, tiles[i].GetY()))
			{
				return false;
			}
		}
		break;
	default:
		break;
	}

	return true;
}

void Block::MoveHorizontally(Direction moveDirection)
{
	switch (moveDirection)
	{
	case Direction::Left:
		for (int i = 0 ; i< 4; i++)
		{
			tiles[i].Move(-1, 0);
		}
		break;
	case Direction::Right:
		for (int i = 0; i < 4; i++)
		{
			tiles[i].Move(1, 0);
		}
		break;
	default:
		break;
	}
}

Tile Block::GetTile(int tileIndex)
{
	if (tileIndex >= 4 || tileIndex < 0)
	{
		return Tile();
	}

	return tiles[tileIndex];
}
