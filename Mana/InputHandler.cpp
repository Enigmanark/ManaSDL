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
	while (SDL_PollEvent(&event)) {
		if(event.type == SDL_QUIT) {
			TheGame::Instance()->Quit();
		}

		else if (event.type == SDL_MOUSEMOTION) {
			m_mousePosition->SetX(event.motion.x);
			m_mousePosition->SetY(event.motion.y);
		}

		else if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				m_mouseButtonStates[LEFT] = true;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE) {
				m_mouseButtonStates[MIDDLE] = true;
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				m_mouseButtonStates[RIGHT] = true;
			}
		}

		else if (event.type == SDL_MOUSEBUTTONUP) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				m_mouseButtonStates[LEFT] = false;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE) {
				m_mouseButtonStates[MIDDLE] = false;
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				m_mouseButtonStates[RIGHT] = false;
			}
		}
	}
}

Vector2D* InputHandler::GetMousePosition() {
	return m_mousePosition;
}

bool InputHandler::IsMouseButtonDown(int number) {
	return m_mouseButtonStates[number];
}

InputHandler::~InputHandler() {
	delete m_keyStates;
}

void InputHandler::Clean() {
	delete m_keyStates;

}