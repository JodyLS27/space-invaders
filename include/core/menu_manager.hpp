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

		void set_current_option(int16_t current_option);
		void set_next_option(int16_t next_option);

		int16_t get_current_option();
		int16_t get_next_option();

		// Primary functions of the Menu manager for the current state
		void init();
		void update();
		void draw();

		void switch_menu(std::unique_ptr<IMenu> new_menu);

		// Pointer for the next menu to load
		std::unique_ptr<IMenu> next_menu;

	protected:
		// Pointer for the current menu to load
		std::unique_ptr<IMenu> current_menu;

	private:
		int16_t m_current_option{};
		int16_t m_next_option{};

	};
}