#pragma once
#include <SFML/Graphics.hpp>

namespace player
{
	class Player
	{
	private:
		Player();

		sf::Vector2f m_position{};
		sf::Vector2i m_direction{};
		sf::RectangleShape m_shape{};

		int m_score{};
		int m_jump_height{};
		bool m_can_jump{};

		void update_position(sf::Vector2i direction);

	public:
		void set_position(sf::Vector2f position);
		void set_direction(sf::Keyboard::Key);
		void set_shape(sf::Vector2f shape_size, sf::Color color = sf::Color::Red);
		

		sf::Vector2f get_position();
		sf::RectangleShape get_shape();

	};

}