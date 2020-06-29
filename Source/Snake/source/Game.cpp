#include "..\include\Game.h"

Game::Game() 
	: m_window{ sf::VideoMode{Game_Constants::WINDOW_X, Game_Constants::WINDOW_Y}, "Snaker" }, m_world{ sf::Vector2u{Game_Constants::WINDOW_X, Game_Constants::WINDOW_Y} },
	 m_elapsed{0.f}, m_fps{60.f}, m_frameTime{ 1.f / m_world.getSnake()->GetSpeed() }, 
	m_isHighScore{ false }, m_highScoreFilePath{ "../../../Game/data/saves/highscore.txt" }
{
	//TODO: I Hate everything about this constructor. There is too much going on that is potential for headaches
	m_window.setKeyRepeatEnabled(false);

	

	// THIS SHOULD NOT BE IN THE CONSTRUCTOR
	std::ifstream ifs{ m_highScoreFilePath };
	ifs >> m_highScore;
	ifs.close();
	
}

Game::~Game()
{
	// THIS IS SOMETHING THAT THE DESTRUCTOR SHOULD NOT BE DOING!
	std::ofstream ofs{ m_highScoreFilePath };
	ofs << m_highScore;
	ofs.close();
}

void Game::Run()
{
	resetGame();
	while (m_window.isOpen())
	{
		Input();
		if (m_elapsed >= m_frameTime)
		{			
			Update();
			m_elapsed -= m_frameTime;
		}
		
		Render();
		m_elapsed += m_clock.restart().asSeconds();
	}
}

void Game::resetGame()
{
	initDefaultState();
}

void Game::initDefaultState()
{
	if (m_pCurrentState) delete m_pCurrentState;

	m_pCurrentState = new SnakeState::PendingState{ *this, m_window };
}

void Game::Input()
{	
	m_pCurrentState->handleInput();	
}

void Game::Update()
{
	m_pCurrentState->handleUpdate();	
}

void Game::Render()
{
	m_pCurrentState->handleRender();
}


bool Game::IsHighScore() const
{
	return m_isHighScore;
}

sf::RenderWindow& Game::Window()
{
	return m_window;
}

void Game::SignalClose()
{
	// TODO: Create proper game shut down sequence

	// in the meantime
	m_window.close();
}


