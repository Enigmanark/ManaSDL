#include "InputHandler.h"
#include "Game.h"

InputHandler* TheInputHandler::m_Instance = 0;

bool InputHandler::IsKeyDown(SDL_Scancode p_key) {
	if (m_keyStates != 0) {
		if (m_keyStates[p_key] == 1) {
			return true;
		}
	}
	return false;
}

void InputHandler::Update() {
	m_keyStates = SDL_GetKeyboardState(0);
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

InputHandler::~InputHandler() {
	delete m_keyStates;
}

void InputHandler::Clean() {
	delete m_keyStates;

}