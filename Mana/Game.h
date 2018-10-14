#pragma once
#include "SDL.h"
#ifndef __Game__
#define __Game__

typedef Game TheGame;

class Game {

public:

	static Game* Instance() {
		if (s_Instance == 0) {
			s_Instance = new Game();
			return s_Instance;
		}
		else return s_Instance;
	}

	bool Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void Render();
	void Update();
	void HandleEvents();
	void Clean();

	bool IsRunning() {return m_running; }

	SDL_Renderer* GetRenderer();

private:

	Game();
	~Game();

	static Game* s_Instance;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	bool m_running;
};


#endif // !__Game__

