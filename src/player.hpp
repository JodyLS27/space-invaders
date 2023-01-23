#pragma once
#include <SFML/Graphics.hpp>

namespace player
{
	class Player
	{
	private:
		sf::Vector2f m_position{};
		sf::Vector2i m_direction{};
		sf::RectangleShape m_shape{};

		int m_score{};
		int m_speed{};

		void update_position(sf::Vector2i direction, float delta_time);

	public:
		Player();

		void set_position(sf::Vector2f position);
		void set_direction(sf::Keyboard::Key, float delta_time);
		void set_shape(sf::Vector2u window_size, sf::Vector2f shape_size, sf::Color color = sf::Color::Red);
		void set_score(int score);


		sf::Vector2f get_position();
		sf::RectangleShape get_shape();
		int get_score();
	};

}