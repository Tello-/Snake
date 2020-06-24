#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

//#define DEBUG_MODE

#ifdef DEBUG_MODE
#include <fstream>
#include <iostream>
#endif // DEBUG_MODE




struct SnakeSegment
{
	SnakeSegment(const sf::Vector2i& _pos = sf::Vector2i{ 1, 1 })
		: position{ _pos } {}
	SnakeSegment(int _x, int _y) : position{ sf::Vector2i{_x, _y} } {}
	sf::Vector2i position; // integer (x,y) pair defining a grid coordinate position
};

using SnakeContainer = std::vector<SnakeSegment>;
enum class Direction { None, Up, Down, Left, Right };

class Snake {
public:
	Snake(int l_blockSize, const sf::Vector2i& _pos);
	~Snake();
	// Helper methods.
	void SetDirection(Direction l_dir);
	Direction GetDirection();
	void IncreaseSpeed(int _increment) { m_speed += _increment; }
	int GetSpeed();
	sf::Vector2i GetPosition();
	void setPosition(sf::Vector2i);
	int GetLives();
	int GetScore();
	void IncreaseScore(); // TODO: Determine if this pertains to a snake.. 
	bool HasLost();
	void Lose(); // Handle losing here.
	void ToggleLost();
	void Extend(); // Grow the snake.
	void Reset(); // Reset to starting position.
	void Move(); // Movement method.
	void Tick(); // Update method.
	
	void Render(sf::RenderWindow& l_window);
private:
	void CheckCollision(); // Checking for collisions.
	void Cut(int l_segments); // Method for cutting snake.


	SnakeContainer m_snakeBody; // Segment vector.
	SnakeContainer m_cutSegments; // container 
	int m_size; // Size of the graphics.
	Direction m_dir; // Current direction.
	int m_speed; // Speed of the snake.
	int m_lives; // Lives.
	int m_score; // Score.
	bool m_lost; // Losing state.
	sf::RectangleShape m_bodyRect; // Shape used in rendering. // TODO: Take graphic rep out of snake object
};