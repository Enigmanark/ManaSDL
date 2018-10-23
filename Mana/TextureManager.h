#pragma once
#include <iostream>
#include <map>
#include "SDL.h"
#include "Vector2D.h"
#ifndef __TextureManager__
#define __TextureManager__

class TextureManager {

public:

	static TextureManager* Instance() {
		if (s_Instance == 0) {
			s_Instance = new TextureManager();
			return s_Instance;
		}
		else return s_Instance;
	}

	void ClearFromMap(std::string s_id);
	bool Load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void Draw(std::string id, float x, float y, int p_width, int p_height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawRegion(std::string id, float p_srcX, float p_srcY, int p_Width, int p_Height, float p_destX, float p_destY,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	Vector2D GetTextureSize(std::string p_id);

private:
	TextureManager() {}
	~TextureManager() {}

	static TextureManager* s_Instance;
	std::map<std::string, SDL_Texture*> m_textureMap;
};

typedef TextureManager TheTextureManager;

#endif // !__TextureManager__
