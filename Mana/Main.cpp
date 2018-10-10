#include "Game.h"

Game* game;

int main() {
	game = new Game();

	game->Init();

	while (game->IsRunning()) {
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	game->Clean();
	return 0;
}