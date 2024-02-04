#include "core/game_manager.hpp"

void game_manager::init()
{
	// TODO: Test the main_menu structure
	//		- Load the Init() on the MenuManager class (Game starts here)
	// TODO: Setup the player controller ptr	//	
	// Call Update function to get the main game loop moving.

	// TODO: Look into why this line is so broken and causing link errors
	menu::MenuManager menu_manager;

	/*update(menu_manager);*/
	update();
}

void game_manager::update()
{
	//menu_manager.init();
	// Create main game loop structure.
}