#pragma once
#include <iostream>
#include "SDL.h"
#include "Vector2D.h"
#ifndef __GameObject__
#define __GameObject__

class GameObject {

public:
	GameObject() {};
	GameObject(std::string p_id);
	~GameObject();

	std::string GetId();
	void Load(std::string p_textureId);
	virtual void Update();
	virtual void Draw();
	virtual void Clean();
	Vector2D* GetPosition();

protected:
	std::string m_id;
	std::string m_textureId;
	Vector2D* m_position;
	
};
#endif // !__GameObject__

