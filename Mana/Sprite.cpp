#include "Sprite.h"
#include "TextureManager.h"

void Sprite::Load(std::string p_id) {
	m_id = p_id;
}

void Sprite::Draw(SDL_Renderer* p_renderer) {
	TextureManager::Instance()->Draw(m_id, m_x, m_y, p_renderer);
}

void Sprite::SetX(float x) {
	m_x = x;
}

void Sprite::SetY(float y) {
	m_y = y;
}

void Sprite::SetPosition(float x, float y) {
	m_x = x;
	m_y = y;
}

void Sprite::Clean() {

}

void Sprite::Update() {

}