#include "Sprite.h"
#include "TextureManager.h"

Sprite::Sprite(std::string p_id) {
	m_id = p_id;
}

void Sprite::Load(std::string p_textureId) {
	m_textureId = p_textureId;
}

void Sprite::Draw(SDL_Renderer* p_renderer) {
	TextureManager::Instance()->Draw(m_id, m_x, m_y, p_renderer);
}