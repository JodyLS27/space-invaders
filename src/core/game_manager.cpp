#include "core/game_manager.hpp"

void game_manager::init()
{
	// TODO: Test the main_menu structure
	//		- Load the Init() on the MenuManager class (Game starts here)
	// TODO: Setup the player controller ptr	//	
	// Call Update function to get the main game loop moving.

	menu::MenuManager menu_manager;

	update(menu_manager);
}

void game_manager::update(menu::MenuManager& menu_manager)
{
	menu_manager.init();

	int16_t option{};

	while (true)
	{
		// Call current state Update and draw.
		menu_manager.update();
		menu_manager.draw();

		std::cin >> option;

		menu_manager.set_next_option(option);
	}
}