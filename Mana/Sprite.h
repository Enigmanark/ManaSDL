#ifndef __Sprite__
#define __Sprite__

#pragma once
#include "GameObject.h"

class Sprite : public GameObject {

public:
	Sprite(std::string p_id) { GameObject::Init(p_id); }
	virtual void Draw(double p_delta) { 
		GameObject::Draw(p_delta); 
	}
};

#endif // !__Sprite__
