#include "BlockRegistry.h"
#include "Spaceship.h"

Block* BlockRegistry::createFromId(BlockType blockType)
{
	switch (blockType)
	{
	case BlockType::EMPTY:
		return new EmptyBlock();
	case BlockType::HULL:
		return new HullBlock();
	default:
		std::stringstream ss;
		ss << "unexpected blocktype: " << blockType;
		throw new std::exception(ss.str().data());
	}
}
