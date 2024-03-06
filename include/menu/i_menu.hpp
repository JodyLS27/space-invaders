#pragma once

#include <core/menu_controller.hpp>

namespace menu
{
	class IMenu
	{
	public:
		virtual ~IMenu() = default;

		virtual void init() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void set_menu_controller() = 0;
	};
}