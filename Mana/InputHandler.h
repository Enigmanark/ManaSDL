#pragma once
#include "SDL.h"
#include <vector>
#include "Vector2D.h"
#ifndef __InputHandler__
#define __InputHandler__

enum mouse_button {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler {

public:

	static InputHandler* Instance() {
		if (m_Instance == 0) {
			m_Instance = new InputHandler();
			return m_Instance;
		}
		else return m_Instance;
	}

	void Update();
	void Clean();

	Vector2D* GetMousePosition();
	bool IsKeyDown(SDL_Scancode p_key);
	bool IsMouseButtonDown(int number);

private:

	InputHandler() {
		for (int i = 0; i < 3; i++) {
			m_mousePosition = new Vector2D(0, 0);
			m_mouseButtonStates.push_back(false);
		}
	};
	~InputHandler();

	Vector2D* m_mousePosition;
	const Uint8* m_keyStates;
	std::vector<bool> m_mouseButtonStates;

	static InputHandler* m_Instance;
};

typedef InputHandler TheInputHandler;

#endif // !__InputHandler__

