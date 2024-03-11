#pragma once

#include <iostream>

#include "core/menu_Controller.hpp"
#include "menu/i_menu.hpp"
#include "menu/main_menu.hpp"

namespace menu
{
	class SettingsMenu : public menu::IMenu
	{
	public:
		SettingsMenu();
		~SettingsMenu();

		void init() override;
		void update() override;
		void draw() override;
	};
}