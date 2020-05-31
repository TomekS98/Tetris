#pragma once

#include <stdlib.h>
#include "Block.h"

class BlocksGenerator
{
	int tilesDisplacements[7][4] = {
		1,3,5,7,
		2,4,5,7,
		3,5,4,6,
		3,5,4,7,
		2,3,5,7,
		3,5,7,6,
		2,3,4,5,
	};

	int startingX;
	int startingY;
public:
	BlocksGenerator();
	BlocksGenerator(int startingX, int startingY);
	Block GenerateBlock();
};

