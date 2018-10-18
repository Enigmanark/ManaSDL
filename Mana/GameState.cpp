#include "GameState.h"

void GameState::Update() {
	//update le game objects
	for (size_t i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->Update();
	}
	//Update le state components
	for (size_t i = 0; i < m_stateComponents.size(); i++) {
		m_stateComponents[i]->Update();
	}
}

void GameState::Render() {
	//Render le game objects
	for (size_t i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->Draw();
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
	return 0;
}

GameState::~GameState() {
	Clean();
}

void GameState::Clean() {
	m_gameObjects.clear();
}