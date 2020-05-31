#pragma once

#include "Tile.h"
#include "Direction.h"
#include "PlayField.h"


class Block
{
	Tile tiles[4];
public:
	Block();
	Block(Tile tiles[4]);
	bool CanMoveDown(PlayField playField);
	void MoveDown();
	void Rotate();
	bool CanMoveHorizontally(PlayField playField, Direction moveDirection);
	void MoveHorizontally(Direction moveDirection);
	Tile GetTile(int tileIndex);
};

