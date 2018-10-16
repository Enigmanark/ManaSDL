#pragma once
#include <iostream>
#ifndef __GameState__
#define __GameState__

class GameState {
	
public:

	virtual void Update() = 0;
	virtual void Render() = 0;
	
	virtual bool OnEnter() = 0;
	virtual bool OnExit() = 0;

	virtual std::string GetStateID() = 0;
};
#endif // !__GameState__
