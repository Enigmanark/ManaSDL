#pragma once
#ifndef __InputHandler__
#define __InputHandler__

class InputHandler {

public:

	static InputHandler* Instance() {
		if (m_Instance == 0) {
			return new InputHandler();
		}
		else return m_Instance;
	}

	void Update();
	void Clean();

	bool IsKeyDown(SDL_Scancode p_key);

private:

	InputHandler() {};
	~InputHandler();

	const Uint8* m_keyStates;

	static InputHandler* m_Instance;
};

typedef InputHandler TheInputHandler;

#endif // !__InputHandler__

