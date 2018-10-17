#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

Vector2D* GameObject::GetPosition() {
	return m_position;
}

GameObject::~GameObject() {
	Clean();
}

GameObject::GameObject(std::string p_id, std::string p_parentId) {
	m_id = p_id;
	m_parentId = p_parentId;
	m_position = new Vector2D(0, 0);
}

void GameObject::Load(std::string p_filePath, std::string p_textureId) {
	m_textureId = p_textureId;
	TheTextureManager::Instance()->Load(p_filePath, p_textureId, TheGame::Instance()->GetRenderer());
}

void GameObject::LoadSpriteSheet(std::string p_filePath, std::string p_textureId, int p_xFrames, int p_yFrames, int p_startFrameX, int p_startFrameY) {
	m_textureId = p_textureId;
	TheTextureManager::Instance()->Load(p_filePath, p_textureId, TheGame::Instance()->GetRenderer());
	Vector2D size = TheTextureManager::Instance()->GetTextureSize(p_textureId);
	m_frameWidth = size.GetX() / p_xFrames;
	m_frameHeight = size.GetY() / p_yFrames;
	m_currentFrameX = p_startFrameX;
	m_currentFrameY = p_startFrameY;
}

void GameObject::Update() {
	//Todo
}

void GameObject::Clean() {
	if (!TheGame::Instance()->GetStateMachine()->GetCurrentState()->GameObjectHasTexture(m_textureId)) {
		TheTextureManager::Instance()->ClearFromMap(m_textureId);
	}
	delete m_position;
	delete m_bounds;
}

void GameObject::Draw() {
	TheTextureManager::Instance()->Draw(m_id, GetPosition()->GetX(), GetPosition()->GetY());
}

void GameObject::DrawRegion() {
	int t_srcX = m_frameWidth * m_currentFrameX;
	int t_srcY = m_frameHeight * m_currentFrameY;
	int t_destX = m_position->GetX();
	int t_destY = m_position->GetY();
	TheTextureManager::Instance()->DrawRegion(m_textureId, t_srcX, t_srcY, m_frameWidth, m_frameHeight, t_destX, t_destY);
}

void GameObject::SetBounds(int p_x, int p_y, int p_width, int p_height) {
	m_bounds = new SDL_Rect();
	m_bounds->x = p_x;
	m_bounds->y = p_y;
	m_bounds->w = p_width;
	m_bounds->h = p_height;
}

SDL_Rect* GameObject::GetBounds() {
	return m_bounds;
}

bool GameObject::DoBoundsCollide(SDL_Rect* p_rect) {
	return SDL_HasIntersection(m_bounds, p_rect);
}
