#include "TextureManager.h"
#include "SDL_image.h"
#include "Game.h"
#include <iostream>

TextureManager* TheTextureManager::s_Instance = 0;

bool TextureManager::Load(std::string p_fileName, std::string p_stringId, SDL_Renderer* p_renderer) {
	if (m_textureMap[p_stringId]) {
		std::cout << "Texture already exists with that ID, not adding it twice" << std::endl;
		return true;
	}
	SDL_Surface* t_surface = IMG_Load(p_fileName.c_str());

	if (t_surface == 0) {
		std::cout << "MANA:: Error: TextureManager failed to create surface for item " << p_stringId.c_str() << std::endl;
		return false;
	}

	SDL_Texture* t_texture = SDL_CreateTextureFromSurface(p_renderer, t_surface);

	SDL_FreeSurface(t_surface);

	if (t_texture != 0) {
		m_textureMap[p_stringId] = t_texture;
		std::cout << "MANA:: Log:: TextureManager successfully created texture with id " << p_stringId.c_str() << std::endl;
		return true;
	}
	else {
		std::cout << "MANA:: Error: TextureManager failed to create texture for item " << p_stringId.c_str() << std::endl;
		return false;
	}
}

Vector2D TextureManager::GetTextureSize(std::string p_id) {
	SDL_Rect rect;
	SDL_QueryTexture(m_textureMap[p_id], NULL, NULL, &rect.w, &rect.h);
	return Vector2D((float)rect.w, (float)rect.h);
}

void TextureManager::Draw(std::string p_id, int p_x, int p_y, int p_width, int p_height, SDL_RendererFlip p_flip) {

	SDL_Rect t_srcRect;
	SDL_Rect t_destRect;

	t_srcRect.x = 0;
	t_srcRect.y = 0;
	t_destRect.w = t_srcRect.w = p_width;
	t_destRect.h = t_srcRect.h = p_height;
	t_destRect.x = p_x;
	t_destRect.y = p_y;

	SDL_RenderCopyEx(TheGame::Instance()->GetRenderer(), m_textureMap[p_id], &t_srcRect, &t_destRect, 0, 0, p_flip);
}

void TextureManager::DrawRegion(std::string p_id, int p_srcX, int p_srcY, int p_width, int p_height, int p_destX, int p_destY, SDL_RendererFlip p_flip) {

	SDL_Rect t_srcRect;
	SDL_Rect t_destRect;

	t_srcRect.x = p_srcX;
	t_srcRect.y = p_srcY;
	t_destRect.w = t_srcRect.w = p_width;
	t_destRect.h = t_srcRect.h = p_height;
	t_destRect.x = p_destX;
	t_destRect.y = p_destY;
	SDL_RenderCopyEx(TheGame::Instance()->GetRenderer(), m_textureMap[p_id], &t_srcRect, &t_destRect, 0, 0, p_flip);
}

void TextureManager::ClearFromMap(std::string s_id) {
	m_textureMap.erase(s_id);
}