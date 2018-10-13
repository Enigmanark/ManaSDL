#include "TextureManager.h"
#include "SDL_image.h"

TextureManager* TextureManager::s_Instance = 0;

bool TextureManager::Load(std::string p_fileName, std::string p_stringId, SDL_Renderer* p_renderer) {
	SDL_Surface* t_surface = IMG_Load(p_fileName.c_str());

	if (t_surface == 0) {
		return false;
	}

	SDL_Texture* t_texture = SDL_CreateTextureFromSurface(p_renderer, t_surface);

	SDL_FreeSurface(t_surface);

	if (t_texture != 0) {
		m_textureMap[p_stringId] = t_texture;
		return true;
	}
	else {
		return false;
	}
}

void TextureManager::Draw(std::string p_id, int p_x, int p_y, SDL_Renderer* p_renderer, SDL_RendererFlip p_flip) {

	SDL_Rect t_srcRect;
	SDL_Rect t_destRect;

	SDL_QueryTexture(m_textureMap[p_id], NULL, NULL, &t_srcRect.w, &t_srcRect.h);

	t_srcRect.x = 0;
	t_srcRect.y = 0;
	t_destRect.w = t_srcRect.w;
	t_destRect.h = t_srcRect.h;
	t_destRect.x = p_x;
	t_destRect.y = p_y;

	SDL_RenderCopyEx(p_renderer, m_textureMap[p_id], &t_srcRect, &t_destRect, 0, 0, p_flip);
}