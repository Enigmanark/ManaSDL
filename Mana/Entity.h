#pragma once
#include <iostream>
#include "SDL.h"
#ifndef __Entity__
#define __Entity__

class Entity {

public:
	Entity();
	Entity(std::string p_id);
	~Entity();

	std::string GetId();
	void Load(std::string p_textureId);
	void Update();
	void Draw(SDL_Renderer* p_renderer);
	void Clean();
	void SetX(float x);
	void SetY(float y);
	void SetPosition(float x, float y);

protected:
	std::string m_id;
	std::string m_textureId;

	float m_x;
	float m_y;
};
#endif // !__Entity__

