#ifndef __GameStateComponent__
#define __GameStateComponent__
#pragma once

class GameState;

class GameStateComponent {

public:
	
	void SetParentGameState(GameState* p_state);
	GameState* GetGameState();
	virtual void Update() = 0;

protected:
	GameState* m_gameState;
};

#endif // !__GameStateComponent__