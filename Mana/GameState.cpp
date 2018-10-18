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