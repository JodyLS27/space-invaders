#pragma once

#include <iostream>

#include "core/menu_controller.hpp"
#include "menu/i_menu.hpp"
#include "menu/settings_menu.hpp"

namespace menu
{
	class MainMenu : public menu::IMenu
	{
	public:
		MainMenu();
		~MainMenu();

		void init() override;
		void update() override;
		void draw() override;
	};
}