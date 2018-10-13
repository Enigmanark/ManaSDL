#pragma once
#include <iostream>
#include "SDL.h"
#ifndef __Entity__
#define __Entity__

class Entity {

public:

	Entity();
	~Entity();


	void Load(std::string p_id);
	void Update();
	void Draw(SDL_Renderer* p_renderer);
	void Clean();
	void SetX(float x);
	void SetY(float y);
	void SetPosition(float x, float y);

private:
	std::string m_id;

	float m_x;
	float m_y;
};
#endif // !__Entity__

