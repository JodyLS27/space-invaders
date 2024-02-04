#pragma once

#include <memory>
#include <interface/i_menu_base.hpp>

namespace menu
{
	class MenuManager
	{
	public:
		// Called when the game first starts
		void init();
		void update();


	protected:
		// Pointer for the current menu loaded
		std::unique_ptr<menu::MenuBase> current_menu;
	};
}