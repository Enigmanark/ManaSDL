#pragma once
#include "SDL.h"
#include "GameStateMachine.h"
#ifndef __Game__
#define __Game__

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
	void Quit();

	bool IsRunning() {return m_running; }

	SDL_Renderer* GetRenderer();
	GameStateMachine* GetStateMachine();

	int GetScreenWidth() { return m_screenWidth; }
	int GetScreenHeight() { return m_screenHeight; }

private:

	Game() {};
	~Game() { delete s_Instance; }

	int m_screenWidth;
	int m_screenHeight;

	static Game* s_Instance;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	bool m_running;

	GameStateMachine* m_gameStateMachine;

	GameState* m_initState;

	bool InitSystems();
};

typedef Game TheGame;

#endif // !__Game__

