#pragma once

#include <memory>
#include <utility>
#include <iostream>

#include "menu/i_switch_menu.hpp"
#include "menu/main_menu.hpp"

namespace menu
{
	// forward declare
	class IMenu;

	class MenuManager : public menu::ISwitchMenu
	{
	public:
		MenuManager();
		~MenuManager();

		// Called when the game first starts
		void init();
		void update();

		void switch_menu(std::unique_ptr<IMenu> new_menu);

		// Pointer for the next menu to load
		std::unique_ptr<IMenu> next_menu;

	protected:
		// Pointer for the current menu to load
		std::unique_ptr<IMenu> current_menu;

	private:

	};
}