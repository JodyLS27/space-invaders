#pragma once

#include <core/menu_manager.hpp>

namespace menu
{
	class Menu
	{
	public:		
		virtual ~Menu() = 0;

		virtual void init() = 0;
		virtual void update(menu::MenuManager* menu_manager) = 0;
		virtual void draw() = 0;
	};
}