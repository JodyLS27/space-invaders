#pragma once
#include <SFML/Graphics.hpp>

namespace player
{
	class Player
	{
	private:
		sf::Vector2f m_position{};
		sf::Vector2f m_direction{};
		sf::RectangleShape m_shape{};

		int m_score{};
		int m_speed{};
		int m_width{};
		int m_height{};

	public:
		Player(int score, int speed);

		void set_position(sf::Vector2f position);
		void set_direction(sf::Keyboard::Key);
		void set_shape(sf::Vector2f position, sf::Color color = sf::Color::Red);
		void set_score(int score);

		sf::Vector2f get_position();
		sf::RectangleShape& get_shape();
		sf::RectangleShape const& get_shape() const;
		int get_score();

		void update_position();
	};
}