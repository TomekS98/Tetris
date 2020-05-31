#include "Tile.h"

Tile::Tile()
{
	color = Color::Red;
	xPosition = -1;
	yPosition = -1;
}

Tile::Tile(int xPosition, int yPosition, Color color)
{
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->color = color;
}

Color Tile::GetColor()
{
	return color;
}

void Tile::Move(int dx, int dy)
{
	xPosition += dx;
	yPosition += dy;
}

void Tile::Set(int newX, int newY) 
{
	xPosition = newX;
	yPosition = newY;
}

int Tile::GetX()
{
	return xPosition;
}

int Tile::GetY()
{
	return yPosition;
}
