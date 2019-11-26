#include "Snake.hpp"

Snake::Snake(int _blockSize, const sf::Vector2i& _pos) : m_size{_blockSize}
{
	Reset();
	m_snakeBody.front().position = sf::Vector2i{ _pos };
}

Snake::~Snake()
{
}

void Snake::SetDirection(Direction _dir)
{
	switch (_dir)
	{
	case Direction::Up:
		if (m_dir == Direction::Down) return;
		break;
	case Direction::Down:
		if (m_dir == Direction::Up) return;
		break;
	case Direction::Left:
		if (m_dir == Direction::Right) return;
		break;
	case Direction::Right:
		if (m_dir == Direction::Left) return;
		break;
	};

	m_dir = _dir;
}

Direction Snake::GetDirection()
{
	return m_dir;
}

int Snake::GetSpeed()
{
	return m_speed;
}

sf::Vector2i Snake::GetPosition() 
{
	return (!m_snakeBody.empty() ? m_snakeBody.front().position : sf::Vector2i(1, 1));
}

void Snake::setPosition(sf::Vector2i _pos)
{
	m_snakeBody.front().position = _pos;
}

int Snake::GetLives()
{
	return m_lives;
}

int Snake::GetScore()
{
	return m_score;
}

void Snake::IncreaseScore()
{
	m_score += 1;
}

bool Snake::HasLost()
{
	return m_lost;
}


void Snake::Lose()
{
	Reset();
}

void Snake::ToggleLost()
{
	m_lost = !m_lost;
}

void Snake::Extend()
{
	if (m_snakeBody.empty()) { return; }
	SnakeSegment& tail_head =
		m_snakeBody[m_snakeBody.size() - 1];
	if (m_snakeBody.size() > 1) {
		SnakeSegment& tail_bone =
			m_snakeBody[m_snakeBody.size() - 2];
		if (tail_head.position.x == tail_bone.position.x) {
			if (tail_head.position.y > tail_bone.position.y) {
				m_snakeBody.push_back(SnakeSegment(
					tail_head.position.x, tail_head.position.y + 1));
			}
			else {
				m_snakeBody.push_back(SnakeSegment(
					tail_head.position.x, tail_head.position.y - 1));
			}
		}
		else if (tail_head.position.y == tail_bone.position.y) {
			if (tail_head.position.x > tail_bone.position.x) {
				m_snakeBody.push_back(SnakeSegment(
					tail_head.position.x + 1, tail_head.position.y));
			}
			else {
				m_snakeBody.push_back(SnakeSegment(
					tail_head.position.x - 1, tail_head.position.y));
			}
		}
	}
	else {
		if (m_dir == Direction::Up) {
			m_snakeBody.push_back(SnakeSegment(
				tail_head.position.x, tail_head.position.y + 1));
		}
		else if (m_dir == Direction::Down) {
			m_snakeBody.push_back(SnakeSegment(
				tail_head.position.x, tail_head.position.y - 1));
		}
		else if (m_dir == Direction::Left) {
			m_snakeBody.push_back(SnakeSegment(
				tail_head.position.x + 1, tail_head.position.y));
		}
		else if (m_dir == Direction::Right) {
			m_snakeBody.push_back(SnakeSegment(
				tail_head.position.x - 1, tail_head.position.y));
		}
	}
}

void Snake::Reset()
{
	m_snakeBody.clear();
	m_cutSegments.clear();
	m_snakeBody.push_back(SnakeSegment(4,4));
#ifdef DEBUG_MODE
	std::ifstream fs{ "testsnake.txt" };
	//fs.open( "testsnake.txt" );
	int x, y;
	if (fs.is_open())
	{
		while (fs >> x >> y)
		{
			m_snakeBody.push_back(SnakeSegment{ x, y });
		}
		fs.close();
	}

	else std::cout << "Unable to open file";
#endif // DEBUG_MODE

	


	m_bodyRect.setSize(sf::Vector2f{ static_cast<float>(m_size),static_cast<float>(m_size) });
	m_bodyRect.setOutlineThickness(-2);
	m_bodyRect.setOutlineColor(sf::Color(84, 140, 58, 255));
	m_dir = { Direction::None };
	m_speed = { 10 };
	m_lives = { 2 };
	m_score = { 0 };
	m_lost = { false };
	
}

void Snake::Move()
{
	for (int i = m_snakeBody.size() - 1; i > 0; --i) {
		m_snakeBody[i].position = m_snakeBody[i - 1].position;
	}
	if (m_dir == Direction::Left) {
		--m_snakeBody[0].position.x;
	}
	else if (m_dir == Direction::Right) {
		++m_snakeBody[0].position.x;
	}
	else if (m_dir == Direction::Up) {
		--m_snakeBody[0].position.y;
	}
	else if (m_dir == Direction::Down) {
		++m_snakeBody[0].position.y;
	}
	
}

void Snake::Tick()
{
	if (m_lost) { Lose(); }
	if (m_snakeBody.empty()) { return; }
	if (m_dir == Direction::None) { return; }
	Move();
	CheckCollision();
}

void Snake::Cut(int l_segments)
{
	for (int i = 0; i < l_segments; ++i)
	{
		m_cutSegments.push_back(m_snakeBody.back());
		m_snakeBody.pop_back();
	}
		--m_lives;
	
		if (!m_lives) { m_lost = true; return; }
}


void Snake::Render(sf::RenderWindow& l_window)
{
	if (m_snakeBody.empty()) { return; }
	auto head = m_snakeBody.begin();
	m_bodyRect.setFillColor(sf::Color(156, 216, 95, 255));
	m_bodyRect.setPosition(sf::Vector2f{ m_size * head->position });
	l_window.draw(m_bodyRect);
	if (m_snakeBody.size() > 1)
	{
		for (auto segment = m_snakeBody.begin() + 1; segment != m_snakeBody.end(); ++segment)
		{

			m_bodyRect.setFillColor(sf::Color(31, 63, 54, 255));
			m_bodyRect.setPosition(sf::Vector2f{ static_cast<float>(m_size * segment->position.x), static_cast<float>(m_size * segment->position.y) });
			l_window.draw(m_bodyRect);
		}
	}
	

	for (auto segment : m_cutSegments)
	{
		m_bodyRect.setFillColor(sf::Color::Red);
		m_bodyRect.setPosition(sf::Vector2f{ static_cast<float>(m_size * segment.position.x), static_cast<float>(m_size * segment.position.y) });
		l_window.draw(m_bodyRect);
	}
}

void Snake::CheckCollision()
{
	//if (m_snakeBody.size() < 5) { return; }

	SnakeSegment& head = m_snakeBody.front();
	bool justCut = false;

	for (auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); ++itr)
	{
		if (itr->position == head.position) 
		{
			int segments = m_snakeBody.end() - itr;
			Cut(segments);
			justCut = true;
			break;
		}
	}

	if (!justCut)
	{
		for (auto itr : m_cutSegments)
		{
			if (head.position == itr.position)
			{
				int segments = m_snakeBody.end() - (m_snakeBody.begin()+1);
				Cut(segments);
				break;
			}
		}
	}

}

