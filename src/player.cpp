#include <player.hpp>

namespace player
{
	Player::Player()
		: m_score(0), m_speed(10)
	{}
	// PRIVATE FUNCTIONS
	void Player::update_position(sf::Vector2i direction, float delta_time)
	{
		m_position += static_cast<sf::Vector2f>(direction) * static_cast<float>(m_speed); // *delta_time;
		m_shape.setPosition(m_position);
	}

	// PUBLIC FUNCTIONS
	void Player::set_position(sf::Vector2f position)
	{
		m_position = position;
	}

	void Player::set_direction(sf::Keyboard::Key key, float delta_time)
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
			m_direction = { -1, 0 };
			break;

		case sf::Keyboard::S:
		case sf::Keyboard::Down:
			m_direction = { 0, 1 };
			break;

		case sf::Keyboard::D:
		case sf::Keyboard::Right:
			m_direction = { 1, 0 };
			break;

		default:
			break;

		}

		update_position(m_direction, delta_time);
	}

	void Player::set_shape(sf::Vector2u window_size, sf::Vector2f shape_size, sf::Color color)
	{
		m_shape.setSize(shape_size);
		m_shape.setOrigin({ shape_size.x * 0.5f, shape_size.y * 0.5f });
		m_shape.setPosition({ window_size.x * 0.5f, window_size.y * 0.5f });
		m_shape.setFillColor(color);

		m_position = m_shape.getPosition();
	}

	void Player::set_score(int score)
	{
		m_score = score;
	}

	sf::Vector2f Player::get_position()
	{
		return m_position;
	}

	sf::RectangleShape Player::get_shape()
	{
		return m_shape;
	}

	int Player::get_score()
	{
		return m_score;
	}
}
