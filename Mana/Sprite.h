#ifndef __Sprite__
#define __Sprite__

#pragma once
#include "GameObject.h"

class Sprite : public GameObject {

public:
	Sprite() {};
	Sprite(std::string p_id) { GameObject::Init(p_id); }
	virtual void Draw(double p_delta) { 
		GameObject::Draw(p_delta); 
	}

	virtual void Draw(double p_delta, int p_x, int p_y) {
		TheTextureManager::Instance()->Draw(m_textureId, p_x, p_y, m_frameWidth, m_frameHeight);
	}
};

#endif // !__Sprite__
