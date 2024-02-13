#pragma once

#include <core/menu_manager.hpp>

namespace menu
{
	// Forward declare
	class MenuManager;

	class IMenu
	{
	public: 
		virtual ~IMenu() = default;

		virtual void init() = 0;
		// TODO: Update the Overloading classes with this.
		virtual void update(MenuManager& menu_manager) = 0;
		virtual void draw() = 0;
	};
}