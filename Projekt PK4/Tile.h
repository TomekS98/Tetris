#pragma once

#include "Color.h"

class Tile
{
	int xPosition;
	int yPosition;
	Color color;
public:
	Tile();
	~Tile() {}
	Tile(int xPosition, int yPosition, Color color);
	Color GetColor();
	void Move(int dx, int dy);
	void Set(int newX, int newY);
	int GetX();
	int GetY();
};

