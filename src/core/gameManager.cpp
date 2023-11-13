#include <../include/core/gameManager.hpp>

void gameManager::run()
{
	init();
	update();
}

void gameManager::init()
{
	// Setup the player controller ptr
	// Initialize Textures and load them, might be the render function.
	// Call Update function to get the game to udpate every frame.
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