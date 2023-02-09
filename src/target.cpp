#include <target.hpp>

target::Target::Target(float radius)
	: m_radius(radius)
{}

int ::target::Target::random_val(int lo, int hi)
{
	auto engine = std::default_random_engine{ std::random_device{}() };
	auto distribution = std::uniform_int_distribution<int>{ lo, hi };
	return distribution(engine);
}


sf::Vector2f target::Target::get_position()
{
	return m_position;
}

void target::Target::set_shape(sf::Color colour)
{
	m_shape.setRadius(m_radius);
	m_shape.setOrigin({ m_radius * 0.5f, m_radius * 0.5f });
	m_shape.setPosition(m_position);
	m_shape.setFillColor(colour);
}

void target::Target::set_position(sf::Vector2f position)
{
	m_position = position;
}

sf::CircleShape& target::Target::get_shape()
{
	return m_shape;
}

sf::CircleShape const& target::Target::get_shape() const
{
	return m_shape;
}

sf::Vector2f target::Target::generate_random_position(const sf::Vector2u window_size)
{
	sf::Vector2f position{ static_cast<float>(random_val(0, window_size.x)), static_cast<float>(random_val(0, window_size.y)) };

	// Bounds checking.
	if (position.x < m_radius) { position.x = m_radius; }
	if (position.x > window_size.x - (m_radius * 1.5f)) { position.x = window_size.x - (m_radius * 1.5f); }
	if (position.y < m_radius) { position.y = m_radius; }
	if (position.y > window_size.y - (m_radius * 1.5f)) { position.y = window_size.y - (m_radius * 1.5f); }

	return position;
}

bool target::Target::collision_hit(const sf::Vector2f player_position, const int player_width, const int player_height)
{
	if ((player_position.x + (player_width * 0.5f)) == (m_position.x + m_radius)) { return true; }
	if ((player_position.y + (player_height * 0.5f)) == (m_position.y + m_radius)) { return true; }
}