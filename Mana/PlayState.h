#pragma once
#include "GameState.h"
#ifndef __PlayState__
#define __PlayState__

class PlayState : public GameState {

public:

	virtual void Update();
	virtual void Render();

	virtual bool OnEnter();
	virtual bool OnExit();

	virtual std::string GetStateID() { return m_PlayID; }

private:

	const static std::string m_PlayID;
};

#endif // !__PlayState__