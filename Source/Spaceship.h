#pragma once

#include "includes.h"
#include "GameObject.h"
#include "MiscUtils.h"

class Block;

class Spaceship : public GameObject
{
	std::unordered_map<sf::Vector2i, Block*, std::function<size_t(const sf::Vector2i)>> blocks;

	void addBlock(sf::Vector2i position, Block* block);
	void updateBlocks();

protected:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:

	~Spaceship();
	Spaceship() : blocks{ 100, MiscUtils::hashVector<int> } {}

	void update() override;
	void loadFromFile(const std::string filename);
};

class Block : public sf::Drawable
{
	enum Direction
	{
		NONE = -1,
		UP = 0,
		DOWN,
		LEFT,
		RIGHT,
		NUM_DIRECTIONS
	};

	class State
	{

	};

	friend class Block;

protected:

	sf::Sprite sprite;
	State currentState;
	mutable State futureState;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:

	Block();
	void applyFutureState();

	virtual void determineFutureState() const = 0;
};

class EmptyBlock : public Block
{
public:

	EmptyBlock();
	void determineFutureState() const override;
};

class HullBlock : public Block
{
public:

	HullBlock();
	void determineFutureState() const override;
};
