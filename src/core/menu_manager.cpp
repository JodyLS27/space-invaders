#include "core/menu_manager.hpp"

menu::MenuManager::MenuManager()
{
	std::cout << "\nMenu Manager Constructor() called\n";
}

menu::MenuManager::~MenuManager()
{
	std::cout << "Menu Manager ~Destructor() called\n";
}

void menu::MenuManager::init()
{
	// TODO: Set the current state to be main_menu on first load
	// TODO: call the main menu init() function

	current_menu = std::make_unique<menu::MainMenu>();
}

void menu::MenuManager::update()
{
	// TODO: Run the update of the current state.
}
