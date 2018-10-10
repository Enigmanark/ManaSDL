#pragma once
#include <iostream>
#include <map>
#include "SDL.h"
#ifndef __TextureManager__
#define __TextureManager__

class TextureManager {

public:

	bool Load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void Draw(std::string id, int x, int y, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	std::map<std::string, SDL_Texture*> m_textureMap;
};

#endif // !__TextureManager__
