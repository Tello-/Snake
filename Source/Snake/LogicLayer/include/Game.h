#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "World.hpp"
#include "Snake.hpp"

const unsigned WINDOW_X{ 600 };
const unsigned WINDOW_Y{ 600 };

enum State {PENDING, PLAYING, PAUSED, LOSE};
class Game
{
public:
	Game();
	~Game();
	void Run();
private:
	void Input();
	void Update();
	void Render();

	void CheckCollision();

	bool IsHighScore() const;
	bool m_isHighScore;
	World m_world;	

	sf::RenderWindow m_window;
	sf::View m_gameView;
	sf::View m_loseView;
	
	sf::Clock m_clock;
	float m_elapsed;
	float m_fps;
	float m_frameTime;

	std::string m_highScoreFilePath;

	int m_highScore;

	State m_state;
	
};

