#pragma once
#include <iostream>
#include "SDL.h"
#include "GameObject.h"
#ifndef __Sprite__
#define __Sprite__

class Sprite : public GameObject {
	
public:

	Sprite(std::string p_id);
	~Sprite();

	void Load(std::string p_textureId);
	void Draw(SDL_Renderer* p_renderer);
	void SetBounds(int p_x, int p_y, int p_width, int p_height);
	SDL_Rect* GetBounds();

protected:

	SDL_Rect* m_bounds;
	std::string m_id;
	std::string m_textureId;

};

#endif // !__Sprite__

