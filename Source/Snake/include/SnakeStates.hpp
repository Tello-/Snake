#pragma once
#include "IState.hpp"
#include "IContext.hpp"

namespace SnakeState
{
	class PendingState : public IState
	{
	public:
		PendingState(IContext& context) : IState{ context } {}
		virtual void handleInput() {}
		virtual void handleUpdate() {}
		virtual void handleRender() {}
	};

	class PlayingState : public IState
	{
	public:
		PlayingState(IContext& context) : IState{ context } {}
		virtual void handleInput() {}
		virtual void handleUpdate() {}
		virtual void handleRender() {}
	};

	class PauseState : public IState
	{
	public:
		PauseState(IContext& context) : IState{ context } {}
		virtual void handleInput() {}
		virtual void handleUpdate() {}
		virtual void handleRender() {}
	};

	class LoseState : public IState
	{
	public:
		LoseState(IContext& context) : IState{ context } {}
		virtual void handleInput() {}
		virtual void handleUpdate() {}
		virtual void handleRender() {}
	};
};