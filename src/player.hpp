#pragma once
#include <SFML/Graphics.hpp>

namespace player
{
	class Player
	{
	private:
		sf::Vector2f m_position{};

		int m_jump_height{};
		int m_score{};

		bool m_can_jump{};

	public:
		void set_position(sf::Vector2f position);


		sf::Vector2f get_position();

	};


}