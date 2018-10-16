#include "PlayState.h"

const std::string PlayState::m_PlayID = "PLAY";

void PlayState::Update() {
	//Todo
}

void PlayState::Render() {
	//Todo
}

bool PlayState::OnEnter() {
	std::cout << "Entering Play State" << std::endl;
	return true;
}

bool PlayState::OnExit() {
	std::cout << "Exiting Play State" << std::endl;
	return true;
}