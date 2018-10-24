#include "GameState.h"

void GameState::Update(double p_delta) {
	//update le game objects
	for (size_t i = 0; i < m_gameObjects.size(); i++) {
		if (m_dying) break;
		m_gameObjects[i]->Update(p_delta);
	}
	//Update le state components
	for (size_t i = 0; i < m_stateComponents.size(); i++) {
		if (m_dying) break;
		m_stateComponents[i]->Update(p_delta);
	}

}

void GameState::Render(double p_delta) {
	//Render le game objects
	for (size_t i = 0; i < m_gameObjects.size(); i++) {
		if (m_dying) break;
		m_gameObjects[i]->Draw(p_delta);
	}
}

std::vector<GameObject*> GameState::GetGameObjects() {
	return m_gameObjects;
}

GameObject* GameState::GetGameObjectWithId(std::string p_id) {
	for (size_t i = 0; i < m_gameObjects.size(); i++) {
		if (m_gameObjects[i]->GetId() == p_id) {
			return m_gameObjects[i];
		}
	}
	std::cout << "MANA:: Error:: GameState couldn't find game object with the id " << p_id.c_str() << std::endl;
	return 0;
}

GameStateComponent* GameState::GetComponentWithId(std::string p_id) {
	for (size_t i = 0; i < m_stateComponents.size(); i++) {
		if (m_stateComponents[i]->GetID() == p_id) {
			return m_stateComponents[i];
		}
	}
	std::cout << "MANA:: Error:: GameState couldn't find state component with the id " << p_id.c_str() << std::endl;
	return 0;
}

GameState::~GameState() {
	Clean();
}

void GameState::Clean() {
	m_gameObjects.clear();
}