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

		void set_current_option(int16_t current_option);
		void set_next_option(int16_t next_option);

		int16_t get_current_option();
		int16_t get_next_option();

		void switch_menu(menu::Menu* menu);

	protected:
		// Pointer for the current menu loaded
		std::unique_ptr<menu::Menu> current_menu;

	private:
		// TODO: Remove Temp code
		int16_t m_next_option{};
		int16_t m_current_option{};
	};
}