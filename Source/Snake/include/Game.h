#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "IState.hpp"
#include "SnakeStates.hpp"
#include "World.hpp" 
#include "Snake.hpp"


const unsigned			WINDOW_X{ 600 };
const unsigned			WINDOW_Y{ 600 };

enum State			{PENDING, PLAYING, PAUSED, LOSE};

class Game : public IContext
{
public:
					Game();
					~Game();
	void				Run();


private: // Private Method

	friend			SnakeState::PendingState;
	friend			SnakeState::PlayingState;
	friend			SnakeState::PauseState;
	friend			SnakeState::LoseState;



	void				resetGame();
	void				initDefaultState();

	void				Input();
	void				Update();
	void				Render();

	bool				IsHighScore() const;

	sf::RenderWindow&	Window();

private: // Private Data
	bool				m_isHighScore;
	World			m_world;	

	sf::RenderWindow	m_window;
	
	sf::Clock			m_clock;
	float			m_elapsed;
	float			m_fps;
	float			m_frameTime;

	std::string		m_highScoreFilePath;

	int				m_highScore;

	IState*			m_pCurrentState;
	State			m_state;
	
};

