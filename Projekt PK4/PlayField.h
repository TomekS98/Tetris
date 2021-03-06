#pragma once

#include <list>
#include "Tile.h"
#include "Level.h"

const int WIDTH = 10;
const int HEIGHT = 20;

class PlayField
{
	Tile tiles[WIDTH][HEIGHT];
public:
	bool IsPositionOccupied(int x, int y);
	Tile GetTile(int tileX, int tileY);
	int GetCompleteRowY();
	void RemoveRow(int rowY);
	void AddTile(Tile tileToAdd);
};

