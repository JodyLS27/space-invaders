#pragma once

namespace menu
{
	class Menu
	{
	public:		
		virtual ~Menu() = 0;

		virtual void init() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
	};
}