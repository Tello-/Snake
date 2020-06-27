#pragma once
#include "IState.hpp"

namespace SnakeState
{
	class PendingState : public IState
	{
	public:
		virtual void handleInput() {}
		virtual void handleUpdate() {}
		virtual void handleRender() {}
	};
}