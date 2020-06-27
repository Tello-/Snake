#pragma once
#include <stack>

#include "SFML/Graphics.hpp"

class IContext
{
public:
	IContext() = default;
	virtual ~IContext() {}

	virtual void SignalClose() = 0;
protected:
	
};