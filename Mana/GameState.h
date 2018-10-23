#pragma once
#include <iostream>
#include <vector>
#include "GameObject.h"
#include "GameStateComponent.h"
#ifndef __GameState__
#define __GameState__

class GameState {
	
public:

	~GameState();

	void Clean();
	void Update(double p_delta);
	void Render(double p_delta);
	
	virtual bool OnEnter() = 0;
	virtual bool OnExit() = 0;

	void AddGameStateComponent(GameStateComponent* p_stateComponent) {
		m_stateComponents.push_back(p_stateComponent);
	}

	void AddGameObject(GameObject* p_gObject) {
		m_gameObjects.push_back(p_gObject);
	}

	void SetDeath() { m_dying = true; }

	GameObject* GetGameObjectWithId(std::string p_id);
	
	std::vector<GameObject*> GetGameObjects();

	virtual std::string GetStateID() = 0;
	
	bool GameObjectHasTexture(std::string p_id) {
		for (size_t i = 0; i < m_gameObjects.size(); i++) {
			if (m_gameObjects[i]->GetTextureId() == p_id) {
				return true;
			}
		}
		return false;
	};
protected:
	bool m_dying = false;

	std::vector<GameObject*> m_gameObjects;
	std::vector<GameStateComponent*> m_stateComponents;
};


#endif // !__GameState__
