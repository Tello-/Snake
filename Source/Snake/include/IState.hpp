#pragma once


class IContext; // forward dec

class IState
{
public:
	IState(IContext& context) : m_pContext{ &context } {}
	virtual ~IState() {}

	virtual void handleInput() = 0;
	virtual void handleUpdate() = 0;
	virtual void handleRender() = 0;


protected:
	IContext* m_pContext;
};

