#pragma once
#include <iostream>
#include <vector>
#include "GameObject.h"
#ifndef __GameState__
#define __GameState__

class GameState {
	
public:

	virtual void Update() = 0;
	virtual void Render() = 0;
	
	virtual bool OnEnter() = 0;
	virtual bool OnExit() = 0;

	virtual std::string GetStateID() = 0;

protected:

	std::vector<GameObject*> m_gameObjects;

};


#endif // !__GameState__
