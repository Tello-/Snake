#include "World.hpp"

World::World(sf::Vector2u _windowSize) 
	: m_windowSize{ _windowSize }, m_blockSize{ _windowSize.x / 25 }, m_snake{ getBlockSize(), sf::Vector2i{(int)m_windowSize.x / 2, (int)m_windowSize.y / 2} }
{
	m_apple.setFillColor(sf::Color(242, 84, 26, 255));
	m_apple.setOutlineColor(sf::Color(31, 63, 54, 255));
	m_apple.setOutlineThickness(-2);
	m_apple.setRadius(static_cast<float>(m_blockSize) / 2.f);
	//SpawnApple();
}

void World::SpawnApple()
{
	int maxX = (m_windowSize.x / m_blockSize) - 2;
	int maxY = (m_windowSize.y / m_blockSize) - 2;
	m_applePosition = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
	m_apple.setPosition(static_cast<float>(m_applePosition.x * m_blockSize), static_cast<float>(m_applePosition.y * m_blockSize));
}


// Update method checks to see if snake is colliding with apple
// if it is, the apple is respawned, the snake is extended and the score is increased
// in the future there will be world bounds checking here as well
void World::Update()
{
	m_snake.Tick();
	if (m_snake.GetPosition() == m_applePosition)
	{
		m_snake.Extend();
		m_snake.IncreaseScore();
		if (!(m_snake.GetScore() % 5))
		{
			m_snake.IncreaseSpeed(3);
			std::cout << "World: Snake Speed has increased to " << m_snake.GetSpeed() << std::endl;
		}
		SpawnApple();
	}

	int gridSize_x = m_windowSize.x / m_blockSize;
	int gridSize_y = m_windowSize.y / m_blockSize;
	if (m_snake.GetPosition().x < 0)
	{
		m_snake.setPosition(sf::Vector2i{ m_snake.GetPosition().x + gridSize_x ,m_snake.GetPosition().y });
	}
	if (m_snake.GetPosition().x > gridSize_x)
	{
		m_snake.setPosition(sf::Vector2i{m_snake.GetPosition().x - (gridSize_x +1), m_snake.GetPosition().y});
	}
	if (m_snake.GetPosition().y < 0)
	{
		m_snake.setPosition(sf::Vector2i{m_snake.GetPosition().x, m_snake.GetPosition().y + gridSize_y});
	}
	if (m_snake.GetPosition().y > gridSize_y)
	{
		m_snake.setPosition(sf::Vector2i{ m_snake.GetPosition().x, m_snake.GetPosition().y - (gridSize_y + 1 )});
	}

}

void World::Render(sf::RenderWindow& _window)
{
	_window.draw(m_apple);
	m_snake.Render(_window);
}