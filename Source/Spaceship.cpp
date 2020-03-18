#include "Spaceship.h"
#include "BlockRegistry.h"
#include "AssetManager.h"

//==============================================================================
// Spaceship
//==============================================================================

void Spaceship::addBlock(sf::Vector2i position, Block* block)
{
	blocks.insert({ { position, block } });
}

void Spaceship::updateBlocks()
{
	for (auto kvp : blocks)
	{
		kvp.second->determineFutureState();
	}
	for (auto kvp : blocks)
	{
		kvp.second->applyFutureState();
	}
}

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//std::cout << "draw ship" << std::endl;
	const sf::Transform shipTransform = getTransform();
	for (auto kvp : blocks)
	{
		const sf::Transform transform =
			sf::Transform()
			.translate(sf::Vector2f(kvp.first))
			.combine(shipTransform);
		target.draw(*kvp.second, transform);
	}
}

Spaceship::~Spaceship()
{
	for (auto kvp : blocks)
	{
		delete kvp.second;
	}
}

void Spaceship::update()
{
	updateBlocks();
}

void Spaceship::loadFromFile(const std::string filename)
{
	std::ifstream file;
	file.open("../Assets/Prefabs/" + filename);
	if (!file.is_open())
	{
		std::stringstream ss;
		ss << "could not find file: " << filename;
		throw new std::exception(ss.str().data());
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		int x, y, type;
		ss >> x >> y >> type;
		if (ss.fail())
		{
			// TODO: handle failure
		}
		else
		{
			addBlock(
				sf::Vector2i(x, y),
				BlockRegistry::createFromId((BlockRegistry::BlockType)type)
			);
		}
	}
	file.close();
}

//==============================================================================
// Block
//==============================================================================

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

Block::Block()
{
	// default texture is 16x16
	sprite.setScale(sf::Vector2f(1.f, 1.f) / 16.f);
	sprite.setOrigin(8.f, 8.f);
}

void Block::applyFutureState()
{
	currentState = futureState;
	futureState = State();
}

//==============================================================================
// Empty Block
//==============================================================================

EmptyBlock::EmptyBlock()
{
	sprite.setTexture(AssetManager::preloadedTextures[AssetManager::BLOCK_EMPTY]);
}

void EmptyBlock::determineFutureState() const
{
	futureState = currentState;
}

//==============================================================================
// Hull Block
//==============================================================================

HullBlock::HullBlock()
{
	sprite.setTexture(AssetManager::preloadedTextures[AssetManager::BLOCK_HULL]);
}

void HullBlock::determineFutureState() const
{
	futureState = currentState;
}
