#pragma once

#include <sfml/Graphics.hpp>
#include <random>

namespace target
{
	class Target
	{
	private:
		sf::Vector2f m_position{};
		sf::CircleShape m_shape{};

		float m_radius{};

		int random_val(int lo, int hi);

	public:

		Target(float radius);

		void set_position(sf::Vector2f position);
		void set_shape(sf::Color colour = sf::Color::White);

		// TODO: Remove once test is complete.
		void set_colour(sf::Color colour);

		sf::Vector2f get_position();
		sf::CircleShape& get_shape();
		sf::CircleShape const& get_shape() const;

		sf::Vector2f generate_random_position(const sf::Vector2u window_size);

		bool collision_hit(const sf::Vector2f player_position, const int player_width, const int player_height);
	};
}