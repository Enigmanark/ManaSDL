#pragma once
#include <iostream>
#include "SDL.h"
#include "Vector2D.h"
#include "TextureManager.h"
#ifndef __GameObject__
#define __GameObject__

class GameObject {

public:
	GameObject() {};
	GameObject(std::string p_id);
	~GameObject();

	std::string GetId() { return m_id; }
	std::string GetTextureId() { return m_textureId; }

	void Load(std::string p_filePath, std::string p_textureId);
	void LoadSpriteSheet(std::string p_filePath, std::string p_textureId, int p_xFrames, int p_yFrames, int p_startFrameX, int p_startFrameY);

	virtual void Update(double p_delta);
	virtual void Draw(double p_delta);
	virtual void DrawRegion(double p_delta);
	virtual void Clean();

	void SetPosition(float x, float y);
	Vector2D GetPosition();

	SDL_Rect* GetBounds();
	bool DoBoundsCollide(SDL_Rect* p_rect);

	int GetTextureWidth() { return TextureManager::Instance()->GetTextureSize(m_textureId).GetX(); }
	int GetTextureHeight() { return TextureManager::Instance()->GetTextureSize(m_textureId).GetY(); }

	int GetFrameWidth() { return m_frameWidth; }
	int GetFrameHeight() { return m_frameHeight; }

protected:

	void Init(std::string p_id);

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

