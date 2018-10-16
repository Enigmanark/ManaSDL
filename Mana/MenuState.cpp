#include "MenuState.h"

const std::string MenuState::m_MenuID = "MENU";

void MenuState::Update() {
	//Todo
}

void MenuState::Render() {
	//Todo
}

bool MenuState::OnEnter() {
	std::cout << "Entering Menu State" << std::endl;
	return true;
}

bool MenuState::OnExit() {
	std::cout << "Exiting Menu State" << std::endl;
	return true;
}