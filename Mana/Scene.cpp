#include "Scene.h"
#include <vector>
Entity Scene::CreateEntity(std::string p_id) {
	Entity e = Entity(p_id);
	m_entities.push_back(e);
	return e;
}

Entity Scene::GetEntity(std::string p_id) {
	for (int i = 0; i < m_entities.size(); i ++) {
		Entity e = m_entities[i];
		if (e.GetId()._Equal(p_id)) {
			return e;
		}
	}
}

std::vector<Entity> Scene::GetEntities() {
	return m_entities;
}

void Scene::Update() {

}