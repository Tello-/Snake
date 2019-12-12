#pragma once
#include <time.h>
#include <mtwist.h>
#include "SFML/Graphics.hpp"
#include "Snake.hpp"


class World
{

public:
	World(sf::Vector2u _windowSize);
	~World();
	
	void Update();
	void Render(sf::RenderWindow&);

	const sf::Vector2i ApplePosition() const { return m_applePosition; }
	unsigned getBlockSize() const { return m_blockSize; }

	Snake* getSnake() { return &m_snake; }

private:
	void SpawnApple();

	unsigned m_blockSize;
	sf::Vector2u m_windowSize;

	sf::CircleShape m_apple;
	sf::Vector2i m_applePosition;
	Snake m_snake;
	mtwist* m_pMTState;

};