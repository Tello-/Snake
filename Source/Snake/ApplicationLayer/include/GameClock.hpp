#pragma once
#include <memory>


/* This file describes the interface for a clock to be used as the heart of a game-loop */

namespace sf { class Clock; } // forward decl of SFML clock
class GameClock
{
public:
	explicit GameClock(float _fps = 60.0f);

	float splitLap();
	inline float totalElapsed() const;
	inline float targetFPS() const; 
private:
	std::unique_ptr<sf::Clock> mp_clock;
	float m_targetFramesPerSecond;
	float m_totalElapsed;
};