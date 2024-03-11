#pragma once

#include <memory>

namespace menu
{
	// TODO: See if this is needed, The name space is the same so we
	// I might not need to do a forward declare.
	/*Forward Declare IMenu so its known here*/
	class IMenu;

	class IMenuSwitcher
	{
	public:
		virtual ~IMenuSwitcher() = default;

		/**
		* An Abstract function to switch menus
		**/ 
		virtual void switch_menu(std::unique_ptr<IMenu> next_menu) = 0;
	};
}