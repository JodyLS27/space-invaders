#pragma once

#include <sfml/Graphics.hpp>
#include <random>

namespace target
{
class Target
{
public:

	Target(float radius);

	sf::Vector2f const& get_position() const;
	sf::CircleShape& get_shape();
	sf::CircleShape const& get_shape() const;

	void set_shape(sf::Color colour = sf::Color::White);
	void set_position(const sf::Vector2f& position);

	sf::Vector2f generate_random_position(const sf::Vector2u window_size);

	bool collision_hit(const sf::Vector2f& player_position, const uint16_t player_width, const uint16_t player_height);

private:
	float m_radius{};
	sf::CircleShape m_shape{};

	int random_val(int lo, int hi);
};
}