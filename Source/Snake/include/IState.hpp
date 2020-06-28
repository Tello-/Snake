#pragma once


class Game;
class IState
{
public:
	IState(Game* game) : m_pGame{ game } {}
	virtual ~IState() {}

	virtual void handleInput() = 0;
	virtual void handleUpdate() = 0;
	virtual void handleRender() = 0;

protected:
	Game* m_pGame;
};

