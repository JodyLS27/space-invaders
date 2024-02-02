#include "gameManager.hpp"

void gameManager::run()
{
	init();
	update();
}

void gameManager::init()
{
	// Setup the player controller ptr
	// Initialize Textures and load them. (Might leave this to each category to do)
	//	- Load the Init() on the MenuManager class (Game starts here)
	//  
	// 
	// Call Update function to get the main game loop moving. This is our frame data.
}

void gameManager::createController()
{
	// Check if a controller or Keybord is connected
	// Then return the Correct object for that controller in a pointer.
}

void gameManager::update()
{
	// Create main game loop structure.
}