#include "GameState.h"

void GameState::Update() {
	for (size_t i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->Update();
	}
}

void GameState::Render() {
	for (size_t i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->Draw();
	}
}

void GameState::AddGameObject(GameObject* p_gObject) {
	m_gameObjects.push_back(p_gObject);
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