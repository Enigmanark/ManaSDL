#include "Sprite.h"
#include "TextureManager.h"

Sprite::~Sprite() {
	delete m_position;
	delete m_bounds;
}

Sprite::Sprite(std::string p_id) {
	m_id = p_id;
}

void Sprite::Load(std::string p_textureId) {
	m_textureId = p_textureId;
}

void Sprite::LoadSpriteSheet(std::string p_textureId, int p_width, int p_height, int p_frameX, int p_frameY) {
	m_textureId = p_textureId;
	m_frameHeight = p_height;
	m_frameWidth = p_width;
	m_currentFrameX = p_frameX;
	m_currentFrameY = p_frameY;
}

void Sprite::Update() {
	//Todo
}

void Sprite::Clean() {
	
}

void Sprite::Draw() {
	TextureManager::Instance()->Draw(m_id, GetPosition()->GetX(), GetPosition()->GetY());
}

void Sprite::DrawRegion() {
	int t_srcX = m_frameWidth * m_currentFrameX;
	int t_srcY = m_frameHeight * m_currentFrameY;
	int t_destX = m_position->GetX();
	int t_destY = m_position->GetY();
	TextureManager::Instance()->DrawRegion(m_textureId, t_srcX, t_srcY, m_frameWidth, m_frameHeight, t_destX, t_destY);
}

void Sprite::SetBounds(int p_x, int p_y, int p_width, int p_height) {
	m_bounds = new SDL_Rect();
	m_bounds->x = p_x;
	m_bounds->y = p_y;
	m_bounds->w = p_width;
	m_bounds->h = p_height;
}

SDL_Rect* Sprite::GetBounds() {
	return m_bounds;
}

bool Sprite::DoBoundsCollide(SDL_Rect* p_rect) {
	return SDL_HasIntersection(m_bounds, p_rect);
}
