#pragma once
#include "core/menu_controller.hpp"

namespace game_manager
{
	/**
	* Game initialization
	*
	* This function will load up the Default main manu and the SFML main window in the future.
	*
	**/
	void init();

	/**
	* Primary game loop
	*
	* This Function will enter the primary game loop and update all menue's, Game Modes and characters.
	*
	* @param menu_manager: Object to manage the menus in the game
	**/
	void update(menu::MenuController& menu_manager);
}