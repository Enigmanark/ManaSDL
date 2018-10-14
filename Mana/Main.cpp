#include "Game.h"

int main() {
	Game::Instance()->Init("Mana", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (Game::Instance()->IsRunning()) {
		Game::Instance()->HandleEvents();
		Game::Instance()->Update();
		Game::Instance()->Render();
	}

	Game::Instance()->Clean();
	return 0;
}