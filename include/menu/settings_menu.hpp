#pragma once

#include <iostream>

#include "core/menu_manager.hpp"
#include "menu/i_menu.hpp"
#include "menu/main_menu.hpp"

namespace menu
{
	class SettingsMenu : public menu::Menu
	{
	public:
		SettingsMenu();
		~SettingsMenu() override;

		void init() override;
		void update(menu::MenuManager* menu_manager) override;
		void draw() override;
	};
}