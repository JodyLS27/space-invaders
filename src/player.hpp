#pragma once
#include <SFML/Graphics.hpp>


namespace player
{
	class Player
	{
	private:
		sf::Vector2f m_position{};
		
		int jump_height{};		

		bool can_jump{};
	};
}