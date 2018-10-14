#pragma once
#include <iostream>
#include "SDL.h"
#include "Entity.h"
#ifndef __Sprite__
#define __Sprite__

class Sprite : public Entity {
	
public:

	Sprite(std::string p_id);
	~Sprite();

	void Load(std::string p_textureId);
	void Draw(SDL_Renderer* p_renderer);

protected:

	std::string m_id;
	std::string m_textureId;

};

#endif // !__Sprite__

