#pragma once

#include <iostream>

#include "menu/i_menu.hpp"

namespace menu
{
	class MainMenu : public menu::Menu
	{
	public:
		MainMenu();
		~MainMenu();

		void init() override;
		void update() override;
		void draw() override;

	private:
		int16_t current_option{};
	};
}