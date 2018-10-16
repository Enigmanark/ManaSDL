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

private:

	InputHandler() {};
	~InputHandler() { delete m_Instance; };

	static InputHandler* m_Instance;
};

typedef InputHandler TheInputHandler;

#endif // !__InputHandler__

