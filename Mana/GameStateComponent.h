#ifndef __GameStateComponent__
#define __GameStateComponent__
#pragma once
#include "iostream"

/*
An updatable component class that is to be extended and added directly to a gamestate, an example case
would be for getting input from the player.
*/

class GameState;

class GameStateComponent {

public:

	void Init(GameState* p_state) {
		SetParentGameState(p_state);
	}

	void SetParentGameState(GameState* p_state);
	
	GameState* GetGameState();
	
	virtual void Update(double p_delta) = 0;

	virtual std::string GetID() = 0;

protected:
	
	GameState* m_gameState;
};

#endif // !__GameStateComponent__