#ifndef __GameStateComponent__
#define __GameStateComponent__
#pragma once

/*
An updatable component class that is to be extended and added directly to a gamestate, an example case
would be for getting input from the player.
*/

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