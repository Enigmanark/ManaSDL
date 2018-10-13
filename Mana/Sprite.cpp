#include "Sprite.h"
#include "TextureManager.h"

void Sprite::Load(std::string p_id) {
	m_id = p_id;
}

void Sprite::Draw(SDL_Renderer* p_renderer) {
	TextureManager::Instance()->Draw(m_id, m_x, m_y, p_renderer);
}