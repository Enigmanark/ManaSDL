#pragma once
#include "GameState.h"
#include <vector>
#ifndef __GameStateMachine__
#define __GameStateMachine__

class GameStateMachine {
	
public:

	GameStateMachine() {};
	~GameStateMachine() {
		m_gameStates.clear();
	}

	GameState* GetCurrentState();
	void PushState(GameState* p_state);
	void ChangeState(GameState* p_state);
	void PopState();

private:

	std::vector<GameState*> m_gameStates;

};

#endif // !__GameStateMachine__
