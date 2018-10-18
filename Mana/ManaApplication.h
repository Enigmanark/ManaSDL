#pragma once
#include "Game.h"

class ManaApplication {

public:

	void Init(const char* p_title, int p_width, int p_height, bool p_fullscreen, int p_fps);
	void SetBootState(GameState* p_state);
	void Run();

private:

	int m_frameStart, m_frameTime, m_delayTime, m_fps;
};
