#include "GameStateComponent.h"

GameState* GameStateComponent::GetGameState() {
	return m_gameState;
}

void GameStateComponent::SetParentGameState(GameState* p_state) {
	m_gameState = p_state;
}