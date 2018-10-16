#pragma once
#include <iostream>
#include "SDL.h"
#include "GameObject.h"
#ifndef __Sprite__
#define __Sprite__

class Sprite : public GameObject {
	
public:

	Sprite(std::string p_id);
	~Sprite();
	virtual void Update();
	void Load(std::string p_textureId);
	void LoadSpriteSheet(std::string p_textureId, int p_width, int p_height, int p_frameX, int p_frameY);
	virtual void Draw();
	virtual void DrawRegion();
	virtual void Clean();
	void SetBounds(int p_x, int p_y, int p_width, int p_height);
	SDL_Rect* GetBounds();
	bool DoBoundsCollide(SDL_Rect* p_rect);

protected:

	SDL_Rect* m_bounds;
	std::string m_id;
	std::string m_textureId;
	int m_currentFrameX;
	int m_currentFrameY;
	int m_frameWidth;
	int m_frameHeight;
};

#endif // !__Sprite__

