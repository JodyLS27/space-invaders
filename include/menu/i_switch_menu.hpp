#pragma once

#include <memory>

namespace menu
{
	// Forward Declare
	class IMenu;

	class ISwitchMenu
	{
	public:
		virtual ~ISwitchMenu() = default;

		// Next menu for switching
		virtual void switch_menu(std::unique_ptr<IMenu> next_menu) = 0;
	};
}