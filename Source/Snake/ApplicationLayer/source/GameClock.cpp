#include "../../ApplicationLayer/include/GameClock.hpp"
#include <SFML/System/Clock.hpp>

GameClock::GameClock(float _fps)
	: m_targetFramesPerSecond{_fps}, m_totalElapsed{0.0f}
{

}

/* Used to let the clock know it has reached the beginning or end of a lap
	@return : elapsed time of most recent lap*/
float GameClock::splitLap()
{
	return mp_clock->restart().asSeconds(); // TODO: left off here. time for bed.
}

/* The total time elapsed since last "Tick" event 
	@return : float time since last tick event. */
inline float GameClock::totalElapsed() const
{
	return m_totalElapsed;
}

inline float GameClock::targetFPS() const
{
	return m_targetFramesPerSecond;
}
