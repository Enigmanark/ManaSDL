#include "ManaApplication.h"


void ManaApplication::Init(const char* p_title, int p_width, int p_height, bool p_fullscreen, int p_fps) {
	m_fps = p_fps;
	m_delayTime = 1000.0f / p_fps;
	m_frameStart = 0;
	m_frameTime = 0;

	TheGame::Instance()->Init(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_width, p_height, p_fullscreen);

}

void ManaApplication::SetBootState(GameState* p_state) {
	TheGame::Instance()->GetStateMachine()->ChangeState(p_state);
}

void ManaApplication::Run() {
	
	while (TheGame::Instance()->IsRunning()) {
		//Start of frame
		m_frameStart = SDL_GetTicks();

		TheGame::Instance()->HandleEvents();
		TheGame::Instance()->Update();
		TheGame::Instance()->Render();

		//How long the frame took to complete
		m_frameTime = SDL_GetTicks() - m_frameStart;

		//If the frame went by too fast, then delay the rest of the frame
		if (m_frameTime < m_delayTime) {
			SDL_Delay(m_delayTime - m_frameTime);
		}
	}

	TheGame::Instance()->Clean();

	std::cout << "MANA::Log:: Quitting." << std::endl;
}