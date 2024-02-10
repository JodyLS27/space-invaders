#pragma once

#include <iostream>

#include "core/menu_manager.hpp"
#include "menu/i_menu.hpp"
#include "menu/settings_menu.hpp"

namespace menu
{
	class MainMenu : public menu::Menu
	{
	public:
		MainMenu();
		~MainMenu() override;

		void init() override;
		void update(menu::MenuManager& menu_manager) override;
		void draw() override;
	};
}