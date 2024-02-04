#pragma once

#include <interface/i_menu_base.hpp>

namespace menu
{
	class MainMenu : public menu::MenuBase
	{
	public:
		MainMenu();
		~MainMenu();

		void init() override;
		void update() override;
		void draw() override;
	};
}