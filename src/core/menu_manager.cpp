#include "menu_manager.hpp"
#include "menu/main_menu.hpp"

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
