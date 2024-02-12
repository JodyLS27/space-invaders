#pragma once

#include <memory>
#include <utility>
#include <iostream>

#include "menu/main_menu.hpp"

namespace menu
{
	// forward declare
	class IMenu;

	class MenuManager
	{
	public:
		MenuManager();
		~MenuManager();

		// Called when the game first starts
		void init();
		void update();

		void set_current_option(int16_t current_option);
		void set_next_option(int16_t next_option);

		int16_t get_current_option();
		int16_t get_next_option();

		void switch_menu(std::unique_ptr<IMenu> new_menu);

	protected:
		// Pointer for the current menu loaded
		std::unique_ptr<IMenu> current_menu;

	private:
		// TODO: Remove Temp code
		int16_t m_next_option{};
		int16_t m_current_option{};
	};
}