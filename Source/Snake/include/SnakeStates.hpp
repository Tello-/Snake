#pragma once
#include <stack>
#include "IState.hpp"
#include "IContext.hpp"


namespace SnakeState
{

	// ***************Pending State**************************
	// The initial state of the game. This is the state the game waits in for input to start.
	class PendingState : public IState
	{
	public:
		PendingState(IContext* context, sf::RenderWindow& window) : m_pWindow{ &window } { m_pContext = context; }
		virtual void handleInput()
		{
			sf::Event event;
			while (m_pWindow->pollEvent(event))
			{
				if (event.type == event.Closed)
					m_pWindow->close();
			}
		}
		virtual void handleUpdate() {}
		virtual void handleRender() {}

	private:
		sf::RenderWindow* m_pWindow;
	};
	//:::::::::::End Pending State:::::::::::::::::::::::::::


	// ***************Playing State**************************
	// The state active during normal game play
	class PlayingState : public IState
	{
	public:
		PlayingState(IContext& context) { m_pContext = &context; }
		virtual void handleInput() {}
		virtual void handleUpdate() {}
		virtual void handleRender() {}
	};
	//:::::::::::End Playing State:::::::::::::::::::::::::::


	// ***************Pause State**************************
	// State game takes when paused
	class PauseState : public IState
	{
	public:
		PauseState(IContext& context) { m_pContext = &context; }
		virtual void handleInput() {}
		virtual void handleUpdate() {}
		virtual void handleRender() {}
	};
	//:::::::::::End Pause State:::::::::::::::::::::::::::



	// ***************Lose State**************************
	// State that notifies the player of their loss and prints highscores or similar info
	class LoseState : public IState
	{
	public:
		LoseState(IContext& context) { m_pContext = &context; }
		virtual void handleInput() {}
		virtual void handleUpdate() {}
		virtual void handleRender() {}
	};
	//:::::::::::End Lose State:::::::::::::::::::::::::::

};