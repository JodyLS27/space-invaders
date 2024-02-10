#pragma once

#include <core/menu_manager.hpp>

namespace menu
{
	// Forward declare
	class menu::MenuManager;

	class Menu
	{
	public:
		virtual ~Menu() = 0;

		virtual void init() = 0;
		// TODO: Update the Overloading classes with this.
		virtual void update(menu::MenuManager& menu_manager) = 0;
		virtual void draw() = 0;
	};
}