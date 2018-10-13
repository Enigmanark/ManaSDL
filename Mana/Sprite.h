#pragma once
#include <iostream>
#include "SDL.h"
#ifndef __GameObject__
#define __GameObject__

class Sprite {
	
public:
	
	void Load(std::string p_id);
	void Update();
	void Draw(SDL_Renderer* p_renderer);
	void Clean();
	void SetX(float x);
	void SetY(float y);
	void SetPosition(float x, float y);

protected:

	std::string m_id;
	
	float m_x;
	float m_y;
};

#endif // !__GameObject__

