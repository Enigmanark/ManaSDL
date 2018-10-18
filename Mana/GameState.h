#pragma once
#include <iostream>
#include <vector>
#include "GameObject.h"
#ifndef __GameState__
#define __GameState__

class GameState {
	
public:

	virtual void Clean() = 0;
	void Update();
	void Render();
	
	virtual bool OnEnter() = 0;
	virtual bool OnExit() = 0;

	void AddGameObject(GameObject* p_gObject);
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
	std::vector<GameObject*> m_gameObjects;
};


#endif // !__GameState__
