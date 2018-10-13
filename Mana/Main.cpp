#include "Game.h"

Game* game;

int main() {
	game = new Game();

	game->Init("Mana", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->IsRunning()) {
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	game->Clean();
	return 0;
}