#pragma once
#include <iostream>
#include "SDL.h"
#include "Entity.h"
#ifndef __Sprite__
#define __Sprite__

class Sprite : public Entity {
	
public:

	Sprite();
	~Sprite();

	void Load(std::string p_id);
	void Draw(SDL_Renderer* p_renderer);

protected:

	std::string m_id;

};

#endif // !__Sprite__

