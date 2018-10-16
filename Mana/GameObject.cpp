#include "GameObject.h"

GameObject::GameObject(std::string p_id) {
	m_id = p_id;
}

std::string GameObject::GetId() {
	return m_id;
}

void GameObject::Load(std::string p_textureId) {
	m_textureId = p_textureId;
}

void GameObject::Draw(SDL_Renderer* p_renderer) {

}

void GameObject::Update() {

}

Vector2D* GameObject::GetPosition() {
	return m_position;
}

void GameObject::Clean() {
	delete m_position;
}
