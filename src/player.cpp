#include <player.hpp>

namespace player
{
	Player::Player()
		: m_score(0), m_jump_height(20), m_can_jump(true)
	{}

	void Player::set_position(sf::Vector2f position)
	{
		m_position = position;
	}

	void Player::set_direction(sf::Vector2i direction)
	{
			
	}

	void Player::set_shape(sf::Vector2i shape_size, sf::Color color = sf::Color::Red)
	{

	}


	sf::Vector2f Player::get_position()
	{
		return m_position;
	}

	sf::RectangleShape Player::get_shape()
	{
		return m_shape;
	}
}
