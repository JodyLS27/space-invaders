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
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void set_menu_controller() = 0;

	protected:
		// Reference should be set by set_context().
		MenuManager& m_menu_manager;
	};
}