#pragma once

#include "IState.hpp"
#include "Constants.hpp"



namespace SnakeState
{

	// ***************Pending State**************************
	// The initial state of the game. This is the state the game waits in for input to start.
	// The pending state will be when the splash screen or title screen is displayed.
	// The graphics include: logo, prompt for choice or "any key"
	// Animated ai-controlled snake
	// maybe music
	class PendingState : public IState
	{
	public:
		PendingState(Game& game, sf::RenderWindow& window) // TODO: Determine if States need both the "Game" and he "Window" ref
			: IState{ &game },
			m_pWindow {&window}, 
			m_bCloseFlag{ false } {}		
		
		virtual void handleInput()
		{
			// TODO: Set input flags for update to use to decide what to do/update...
			sf::Event event;
			while (m_pWindow->pollEvent(event))
			{
				if (event.type == event.Closed)
					m_bCloseFlag = true; // I don't think a specific state should be responsible for shutting the game down. I think it should pass that option back to the game class?
			}

			static bool keyLifted{ true };
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			{
				if(keyLifted) 
				{
					keyLifted = false;
					//TODO: then move to playing state
					//IState* nextState( new PlayingState(*m_pGame, *m_pWindow) );
					//m_pGame->transitionToState(nextState);
				}
			}
		}
		virtual void handleUpdate() 
		{
			if (m_bCloseFlag) m_pWindow->close(); // TODO maybe change this so the state cant close the whole game
		}
		virtual void handleRender() 
		{
			m_pWindow->clear(Game_Constants::DARK_COLOR); // TODO replace when no longer needed: Temp color fill for pending state bg
			m_pWindow->display();
			// TODO: Draw Splash Screen
		}

	private:
		sf::RenderWindow* m_pWindow;
		bool m_bCloseFlag;
	};
	//:::::::::::End Pending State:::::::::::::::::::::::::::


	// ***************Playing State**************************
	// The state active during normal game play
	class PlayingState : public IState
	{
	public:
		PlayingState(Game& game, sf::RenderWindow& window) // TODO: Determine if States need both the "Game" and he "Window" ref
			: IState{ &game },
			m_pWindow{ &window },
			m_bCloseFlag{ false } {}

		virtual void handleInput()
		{
			// TODO: Set input flags for update to use to decide what to do/update...
			sf::Event event;
			while (m_pWindow->pollEvent(event))
			{
				if (event.type == event.Closed)
					m_bCloseFlag = true; // I don't think a specific state should be responsible for shutting the game down. I think it should pass that option back to the game class?
			}

		}
		virtual void handleUpdate()
		{
			if (m_bCloseFlag) m_pWindow->close(); // TODO maybe change this so the state cant close the whole game
		}
		virtual void handleRender()
		{
			m_pWindow->clear(Game_Constants::MID_COLOR); // TODO replace when no longer needed: Temp color fill for pending state bg
			m_pWindow->display();
		}

	private:
		sf::RenderWindow* m_pWindow;
		bool m_bCloseFlag;
	};
	//:::::::::::End Playing State:::::::::::::::::::::::::::

}; // end namespace SnakeState