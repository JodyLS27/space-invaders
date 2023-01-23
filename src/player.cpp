#include <player.hpp>

namespace player
{
	Player::Player()
		: m_score(0), m_jump_height(20), m_can_jump(true)
	{}
	// PRIVATE FUNCTIONS
	void Player::update_position(sf::Vector2i direction)
	{
		// TODO: Update Player position.
		// This should be done only on hold not on cycle tick.
	}

	// PUBLIC FUNCTIONS
	void Player::set_position(sf::Vector2f position)
	{
		m_position = position;
	}

	void Player::set_direction(sf::Keyboard::Key key)
	{
		m_direction = { 0, 0 };

		switch (key)
		{
		case sf::Keyboard::W:
		case sf::Keyboard::Up:
			m_direction = { 0, -1 };
			break;

		case sf::Keyboard::A:
		case sf::Keyboard::Left:
			m_direction = { 1, 0 };
			break;

		case sf::Keyboard::S:
		case sf::Keyboard::Down:
			m_direction = { 0, 1 };
			break;

		case sf::Keyboard::D:
		case sf::Keyboard::Right:
			m_direction = { -1, 0 };
			break;

		default:
			break;

			update_position(m_direction);
		}
	}

	void Player::set_shape(sf::Vector2f shape_size, sf::Color color)
	{
		m_shape.setSize(shape_size);
		m_shape.setOrigin({ shape_size.x * 0.5f, shape_size.y * 0.5f });
		m_shape.setFillColor(color);
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
