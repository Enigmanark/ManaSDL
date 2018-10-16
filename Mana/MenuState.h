#pragma once
#include "GameState.h"
#ifndef __MenuState__
#define __MenuState__

class MenuState : public GameState {

public:

	virtual void Update();
	virtual void Render();

	virtual bool OnEnter();
	virtual bool OnExit();

	std::string GetStateID() { return m_MenuID; }

private:

	const static std::string m_MenuID;
};

#endif // !__MenuState__
