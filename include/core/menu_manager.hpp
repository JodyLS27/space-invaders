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
		// Store the current Active menu
		std::unique_ptr<menu::MenuBase> current_menu = std::make_unique<menu::MenuBase>();
	};
}