#pragma once

namespace menu
{
	class Menu
	{
	public:
		virtual void init() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
	};
}