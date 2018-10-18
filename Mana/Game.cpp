#include "Game.h"
#include <iostream>
#include "InputHandler.h"

TheGame* Game::s_Instance = 0;

bool Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "MANA::Log:: SDL initialization successful" << std::endl;
		
		int flags = 0;
		
		if (fullscreen) {
			flags = SDL_WINDOW_FULLSCREEN;
		}

		//init le window
		m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		
		m_screenWidth = width;
		m_screenHeight = height;

		if (m_window != 0) {
			std::cout << "MANA::Log:: Window created successfully" << std::endl;

			//create le renderer
			m_renderer = SDL_CreateRenderer(m_window, -1, 0);

			if (m_renderer != 0) {
				SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
				std::cout << "MANA::Log:: Renderer created successfully" << std::endl;
				//Init systems now
				if (InitSystems()) {
					std::cout << "MANA::Log:: Systems initialized successfully" << std::endl;
					return true;
				}
				
				return false;
				
			}
			else {
				std::cout << "MANA::CRITCAL ERROR:: Failed to create renderer" << std::endl;
				return false;
			}
		}
		else {
			std::cout << "MANA::CRITCAL ERROR:: Failed to create window" << std::endl;
			return false;
		}
	}
	else {
		std::cout << "MANA::CRITCAL ERROR:: SDL Failed to initialize" << std::endl;
		return false;
	}
}

bool Game::InitSystems() {
	std::cout << "MANA::Log:: Initialising Systems.." << std::endl;
	m_running = true;
	m_gameStateMachine = new GameStateMachine();
	return true;
}

void Game::HandleEvents() {
	//Handle le input events
	InputHandler::Instance()->Update();
}

void Game::Render() {
	//Clear le screen
	SDL_RenderClear(m_renderer);

	//Render le gamestate
	GameState* currentState = m_gameStateMachine->GetCurrentState();
	if (currentState == 0) {
		std::cout << "MANA:: CRITICAL ERROR:: There is no current state. Not rendering. Quitting..." << std::endl;
		Quit();
	}else currentState->Render();

	//Present le stuff
	SDL_RenderPresent(m_renderer);
}

void Game::Quit() {
	m_running = false;
}

void Game::Clean() {
	std::cout << "Mana::Log:: Cleaning up.." << std::endl;
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	delete m_gameStateMachine;
	SDL_Quit();
}

GameStateMachine* Game::GetStateMachine() {
	return m_gameStateMachine;
}

SDL_Renderer* Game::GetRenderer() {
	return m_renderer;
}

void Game::Update() {
	//Update le gamestate
	GameState* currentState = m_gameStateMachine->GetCurrentState();
	if (currentState == 0) {
		std::cout << "MANA:: CRITICAL ERROR:: There is no current state. Not updating. Quitting..." << std::endl;
		Quit();
	} else currentState->Update();
}