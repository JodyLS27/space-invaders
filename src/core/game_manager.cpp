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
	// Create main game loop structure.
	int next_option{};
	int current_option{};
	while (true)
	{
		std::cout << "choose a menu item: \n";
		std::cout << "1. main menu: \n";
		std::cout << "2. settings: \n";

		std::cin >> next_option;
		
		// TODO: Check to see if the switching works and if the 
		// pointers are being destroyed when changing.
		if (current_option != next_option)
		{ }

		menu_manager.update();
	}
}