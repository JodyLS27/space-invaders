#pragma once

#include <memory>
#include <iostream>

#include "menu/main_menu.hpp"

namespace menu
{
	class MenuManager
	{
	public:
		MenuManager();
		~MenuManager();

		// Called when the game first starts
		void init();
		void update();


	protected:
		// Pointer for the current menu loaded
		std::unique_ptr<menu::Menu> current_menu;
	};
}