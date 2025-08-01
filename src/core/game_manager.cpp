#include "core/game_manager.hpp"

void game_manager::init()
{
	// TODO: Finalize the Menu Controller
	// TODO: Setup the player controller ptr
	// TODO: 

	// Initialize classes
	menu::MenuController menu_controller;

	menu_controller.init();

	// Run the main game loop
	start(menu_controller);
}

void game_manager::start(menu::MenuController& menu_controller)
{
	// Test Value for now. Will switch this out to the Manager Later.
	int16_t option{};

	// Main game loop start
	while (true)
	{
		// Call current state Update and draw.
		menu_controller.update();
		menu_controller.draw();

		std::cin >> option;

		menu_controller.set_next_option(option);
	}
}

void game_manager::