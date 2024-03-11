#include "core/game_manager.hpp"

void game_manager::init()
{
	// TODO: Setup the player controller ptr	//	
	// Call Update function to get the main game loop moving.
	
	// Load up the main menu
	menu::MenuController menu_manager;
	menu_manager.init();

	// TODO: Rename this function to be more meaningful
	// Run the main game loop
	update(menu_manager);
}

void game_manager::update(menu::MenuController& menu_manager)
{
	// Test Value for now. Will switch this out to the Manager Later.
	int16_t option{};

	// Main game loop start
	while (true)
	{
		// Call current state Update and draw.
		menu_manager.update();
		menu_manager.draw();

		std::cin >> option;

		menu_manager.set_next_option(option);
	}
}