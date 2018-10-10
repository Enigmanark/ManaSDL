#pragma once
#include "SDL.h"
#ifndef __Game__
#define __Game__

class Game {

public:
	Game();
	~Game();

	bool Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void Render();
	void Update();
	void HandleEvents();
	void Clean();

	bool IsRunning() {return m_running; }

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	bool m_running;
};


#endif // !__Game__

