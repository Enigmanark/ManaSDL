#pragma once
#include "SDL.h"
#include <vector>
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

	bool IsKeyDown(SDL_Scancode p_key);

private:

	InputHandler() {
		for (int i = 0; i < 3; i++) {
			m_mouseButtonStates.push_back(false);
		}
	};
	~InputHandler();

	const Uint8* m_keyStates;
	std::vector<bool> m_mouseButtonStates;

	static InputHandler* m_Instance;
};

typedef InputHandler TheInputHandler;

#endif // !__InputHandler__

