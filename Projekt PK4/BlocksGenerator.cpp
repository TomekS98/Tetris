#include "BlocksGenerator.h"

BlocksGenerator::BlocksGenerator()
{
	startingX = -1;
	startingY = -1;
}

BlocksGenerator::BlocksGenerator(int startingX, int startingY)
{
	this->startingX = startingX;
	this->startingY = startingY;
}

Block BlocksGenerator::GenerateBlock()
{
	int randomIndex = rand() % 7;
	Color randomColor = static_cast<Color>(rand() % 7);
	Tile newBlockTiles[4];

	for (int i = 0; i < 4; i++)
	{
		newBlockTiles[i] = Tile(startingX + (tilesDisplacements[randomIndex][i] / 2), startingY + (tilesDisplacements[randomIndex][i] % 2), randomColor);
	}

	Block newBlock(newBlockTiles);

	return newBlock;
}
