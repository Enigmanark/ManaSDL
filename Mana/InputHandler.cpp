#include "InputHandler.h"
#include "SDL.h"
#include "Game.h"

InputHandler* InputHandler::m_Instance = 0;

void InputHandler::Update() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {

		case SDL_QUIT:
			TheGame::Instance()->Quit();
			break;

		default:
			break;
		}
	}
}