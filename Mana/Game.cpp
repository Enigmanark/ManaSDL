#include "Game.h"
#include <iostream>

TheGame* Game::s_Instance = 0;

bool Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL initialization successful";
		
		int flags = 0;
		
		if (fullscreen) {
			flags = SDL_WINDOW_FULLSCREEN;
		}

		//init le window
		m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_window != 0) {
			std::cout << "Window created successfully";

			//create le renderer
			m_renderer = SDL_CreateRenderer(m_window, -1, 0);

			if (m_renderer != 0) {
				SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
				std::cout << "Renderer created successfully";
				//Init systems now
				if (InitSystems()) {
					std::cout << "Systems initialized successfully" << std::endl;
					return true;
				}
				else return false;
				
			}
			else {
				std::cout << "Failed to create renderer";
				return false;
			}
		}
		else {
			std::cout << "Failed to create window";
			return false;
		}
	}
	else {
		std::cout << "SDL Failed to initialize";
		return false;
	}
}

bool Game::InitSystems() {
	std::cout << "Initialising Systems.." << std::endl;
	m_running = true;
	m_gameStateMachine = new GameStateMachine();
	return true;
}

void Game::Render() {
	//Clear le screen
	SDL_RenderClear(m_renderer);

	//Present le stuff
	SDL_RenderPresent(m_renderer);
}

void Game::HandleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		
		case SDL_QUIT:
			m_running = false;
			break;

		default:
			break;
		}
	}
}

void Game::Clean() {
	std::cout << "Cleaning up";
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	delete m_gameStateMachine;
	SDL_Quit();
}

SDL_Renderer* Game::GetRenderer() {
	return m_renderer;
}

void Game::Update() {

}