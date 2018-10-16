#pragma once
#include <iostream>
#include "SDL.h"
#include "Vector2D.h"
#ifndef __GameObject__
#define __GameObject__

class GameObject {

public:
	GameObject() {};
	GameObject(std::string p_id, std::string p_parentId);
	~GameObject();

	std::string GetId() { return m_id; }
	std::string GetTextureId() { return m_textureId; }
	void Load(std::string p_filePath, std::string p_textureId);
	void LoadSpriteSheet(std::string p_filePath, std::string p_textureId, int p_xFrames, int p_yFrames, int p_startFrameX, int p_startFrameY);
	virtual void Update();
	virtual void Draw();
	virtual void DrawRegion();
	virtual void Clean();
	Vector2D* GetPosition();
	void SetBounds(int p_x, int p_y, int p_width, int p_height);
	SDL_Rect* GetBounds();
	bool DoBoundsCollide(SDL_Rect* p_rect);

protected:
	std::string m_parentId;
	std::string m_id;
	std::string m_textureId;
	Vector2D* m_position;
	SDL_Rect* m_bounds;
	int m_currentFrameX;
	int m_currentFrameY;
	int m_frameWidth;
	int m_frameHeight;
};
#endif // !__GameObject__

