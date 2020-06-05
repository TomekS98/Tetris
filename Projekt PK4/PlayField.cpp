#include "PlayField.h"


bool PlayField::IsPositionOccupied(int x, int y)
{
	return tiles[x][y].GetX() != -1 && tiles[x][y].GetY() != -1;
}

Tile PlayField::GetTile(int tileX, int tileY)
{
	if (tileX >= WIDTH || tileX < 0)
	{
		return Tile();
	}

	if (tileY >= HEIGHT || tileY < 0)
	{
		return Tile();
	}

	return tiles[tileX][tileY];
}

int PlayField::GetCompleteRowY()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		int count = 0;

		for (int j = 0; j < WIDTH; j++)
		{
			if (IsPositionOccupied(j, i))
			{
				count++;
			}
		}

		if (count == WIDTH)
		{
			return i;
		}
	}

	return -1;
}

void PlayField::RemoveRow(int rowY)
{
	for (int i = rowY - 1; i >= 0; i--)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			tiles[j][i + 1] = tiles[j][i];
			tiles[j][i + 1].Move(0, 1);
		}
	}
}

void PlayField::AddTile(Tile tile)
{
	if (tile.GetX() == -1 && tile.GetY() == -1)
	{
		return;
	}

	tiles[tile.GetX()][tile.GetY()] = tile;
}


