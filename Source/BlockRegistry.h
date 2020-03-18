#pragma once

class Block;

namespace BlockRegistry
{
	enum BlockType
	{
		NONE = -1,
		EMPTY = 0,
		HULL,
		NUM_BOCK_TYPES
	};

	Block* createFromId(BlockType blockType);
};

