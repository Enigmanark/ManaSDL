#pragma once
#include <iostream>
#include <vector>
#include "Entity.h"

#ifndef __Scene__
#define __Scene__

class Scene {

public:

	Scene();
	~Scene();

	void Update();
	void Draw();
	void Clean();
	Entity CreateEntity(std::string p_id);
	Entity GetEntity(std::string p_id);
	std::vector<Entity> GetEntities();

private:

	std::vector<Entity> m_entities;

};
#endif // !__Scene__
