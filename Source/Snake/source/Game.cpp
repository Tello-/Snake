#include "..\include\Game.h"

Game::Game() 
	: m_window{ sf::VideoMode{WINDOW_X, WINDOW_Y}, "Snaker" }, m_world{ sf::Vector2u{WINDOW_X, WINDOW_Y} }, 
	 m_elapsed{0.f}, m_fps{60.f}, m_frameTime{ 1.f / m_world.getSnake()->GetSpeed() }, 
	m_isHighScore{ false }, m_highScoreFilePath{ "../../../Game/data/saves/highscore.txt" }, m_gameView{ sf::FloatRect{0.f, 0.f, WINDOW_X, WINDOW_Y} },
	m_state{State::PLAYING}
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

void Game::Input()
{
	
	
	
}

void Game::Update()
{

	switch (m_state)
	{
	case PENDING:
		break;
	case PLAYING:
		m_world.Update();
		if (m_world.getSnake()->GetScore() > m_highScore)
		{
			m_highScore = true;
			m_highScore = m_world.getSnake()->GetScore();
		}

		if (m_world.getSnake()->HasLost())
		{
			m_state = State::LOSE;
		}
		break;
	case PAUSED:
		break;
	case LOSE:
		break;
	default:
		break;
	};
	
}

void Game::Render()
{
	m_window.clear(sf::Color(84, 140, 58, 255));
	switch (m_state)
	{
	case PENDING:
		break;
	case PLAYING:
		m_world.Render(m_window);  // TODO replace temporary render setup
		DrawShadowText();			// TODO this is a terrible method
	
		break;
	case PAUSED:
		break;
	case LOSE:
		break;
	default:
		break;
	};
	m_window.display();
}


bool Game::IsHighScore() const
{
	return m_isHighScore;
}


