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

	// TODO: Replace temp code with proper game loop
	// --- Temp Start ---
	int16_t option{};

	while (true)
	{

		std::cout << "choose a menu item\n";
		std::cout << "1. Main Menu\n";
		std::cout << "2. Sttings\n";
		std::cout << "3. Exit\n";

		std::cin >> option;

		menu_manager.set_next_option(option);

		menu_manager.update();
	}
	// --- Temp End ---
}