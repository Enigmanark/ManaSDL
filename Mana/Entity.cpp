#include "Entity.h"

void Entity::Load(std::string p_id) {
	m_id = p_id;
}

void Entity::Draw(SDL_Renderer* p_renderer) {

}

void Entity::Update() {

}

void Entity::SetX(float x) {
	m_x = x;
}

void Entity::SetY(float y) {
	m_y = y;
}

void Entity::SetPosition(float x, float y) {
	m_x = x;
	m_y = y;
}

void Entity::Clean() {

}
