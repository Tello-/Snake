#include "..\include\Game.h"

Game::Game() 
	: m_window{ sf::VideoMode{WINDOW_X, WINDOW_Y}, "Snaker" }, m_world{ sf::Vector2u{WINDOW_X, WINDOW_Y} }, 
	 m_elapsed{0.f}, m_fps{60.f}, m_frameTime{ 1.f / m_world.getSnake()->GetSpeed() }, 
	m_isHighScore{ false }, m_highScoreFilePath{ "../../../Game/data/saves/highscore.txt" }, m_gameView{ sf::FloatRect{0.f, 0.f, WINDOW_X, WINDOW_Y} },
	m_state{State::PLAYING}
{
	//TODO: I Hate everything about this constructor. There is too much going on that is potential for headaches
	m_window.setKeyRepeatEnabled(false);
}

Game::~Game()
{
	
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
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == event.Closed)
			m_window.close();
	}

	switch (m_state)
	{
	case PENDING:
		break;
	case PLAYING:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			m_world.getSnake()->SetDirection(Direction::Up);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			m_world.getSnake()->SetDirection(Direction::Left);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			m_world.getSnake()->SetDirection(Direction::Down);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			m_world.getSnake()->SetDirection(Direction::Right);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_state = State::PAUSED;
		}
		break;
	case PAUSED:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_state = State::PLAYING;
		}
		break;
	case LOSE:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			m_world.getSnake()->Lose();
			m_state = State::PLAYING;
		}
		break;
	default:
		break;
	};
	
	
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


