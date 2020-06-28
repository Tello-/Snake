#pragma once

#include "IState.hpp"



namespace SnakeState
{

	// ***************Pending State**************************
	// The initial state of the game. This is the state the game waits in for input to start.
	class PendingState : public IState
	{
	public:
		PendingState(Game& game, sf::RenderWindow& window)
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
		}
		virtual void handleUpdate() 
		{
			 
		}
		virtual void handleRender() 
		{
			// TODO: Draw Background
			// TODO: Draw Splash Screen
		}

	private:
		//Game* m_pGame;
		sf::RenderWindow* m_pWindow;
		bool m_bCloseFlag;
	};
	//:::::::::::End Pending State:::::::::::::::::::::::::::


//	// ***************Playing State**************************
//	// The state active during normal game play
//	class PlayingState : public IState
//	{
//	public:
//		PlayingState(Game& game) : IState{ game }
//		virtual void handleInput() 
//		{
//			/*This is the code that was the structure for the previous implementation
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
//			{				
//			}
//			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
//			{
//			}
//			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
//			{
//			}
//			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
//			{
//			}
//			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//			{
//			}*/
//		}
//		virtual void handleUpdate() {}
//		virtual void handleRender() {}
//	private:
//		//Game* m_pGame;
//	};
//	//:::::::::::End Playing State:::::::::::::::::::::::::::
//
//
//	// ***************Pause State**************************
//	// State game takes when paused
//	class PauseState : public IState
//	{
//	public:
//		PauseState(Game& game) { m_pGame = &game; }
//		virtual void handleInput() {}
//		virtual void handleUpdate() {}
//		virtual void handleRender() {}
//
//	private:
//		//Game* m_pGame;
//	};
//	//:::::::::::End Pause State:::::::::::::::::::::::::::
//
//
//
//	// ***************Lose State**************************
//	// State that notifies the player of their loss and prints highscores or similar info
//	class LoseState : public IState
//	{
//	public:
//		LoseState(Game& game) { m_pGame = &game; }
//		virtual void handleInput() {}
//		virtual void handleUpdate() {}
//		virtual void handleRender() {}
//
//	private:
//		//Game* m_pGame;
//	};
//	//:::::::::::End Lose State:::::::::::::::::::::::::::
//
};