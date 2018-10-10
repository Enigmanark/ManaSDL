#pragma once
#include <iostream>
#include "SDL.h"
#ifndef __TextureManager__
#define __TextureManager__

class TextureManager {

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

};

#endif // !__TextureManager__
