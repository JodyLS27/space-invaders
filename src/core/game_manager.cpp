#include "core/game_manager.hpp"

void game_manager::init()
{
	// TODO: Setup the player controller ptr

	// Initialize classes
	menu::MenuController menu_controller;

	menu_controller.init();

	// TODO: Rename this function to be more meaningful
	// Run the main game loop
	run(menu_controller);
}

void game_manager::run(menu::MenuController& menu_controller)
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