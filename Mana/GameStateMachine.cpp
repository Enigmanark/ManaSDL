#include "GameStateMachine.h"

GameState* GameStateMachine::GetCurrentState() {
	if (m_gameStates.size() == 0) {
		return 0;
	}
	else return m_gameStates.back();
}

void GameStateMachine::PushState(GameState* p_state) {
	m_gameStates.push_back(p_state);
	m_gameStates.back()->OnEnter();
}

//removes the current state, but first checks if there actually is one obviously
void GameStateMachine::PopState() {
	if (!m_gameStates.empty()) {
		if (m_gameStates.back()->OnExit()) {
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}

void GameStateMachine::ChangeState(GameState* p_state) {
	//If states not empty
	if (!m_gameStates.empty()) {
		//If they're the same state do nothing
		if (m_gameStates.back()->GetStateID() == p_state->GetStateID()) {
			return;
		}

		//They're not the same so exit it then delete it
		if (m_gameStates.back()->OnExit()) {
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
	
	//If we make it here then add the state and initialize it
	m_gameStates.push_back(p_state);
	m_gameStates.back()->OnEnter();
}