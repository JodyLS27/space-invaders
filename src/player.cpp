#include <player.hpp>


player::Player::Player(int score, int speed)
	: m_score(score), m_speed(speed), m_width(25), m_height(25)
{}
// PRIVATE FUNCTIONS


// PUBLIC FUNCTIONS
void player::Player::set_position(sf::Vector2f position)
{
	m_position = position;
}

void player::Player::set_direction(sf::Keyboard::Key key)
{
	m_direction = { 0.0f, 0.0f };

	switch (key)
	{
	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		m_direction = { 0.0f, -1.0f };
		break;

	case sf::Keyboard::A:
	case sf::Keyboard::Left:
		m_direction = { -1.0f, 0.0f };
		break;

	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		m_direction = { 0.0f, 1.0f };
		break;

	case sf::Keyboard::D:
	case sf::Keyboard::Right:
		m_direction = { 1.0f, 0.0f };
		break;

	default:
		break;

	}
}

void player::Player::set_shape(sf::Vector2f position, sf::Color color)
{
	m_shape.setSize({ static_cast<float>(m_width), static_cast<float>(m_height) });
	m_shape.setOrigin({ m_width * 0.5f, m_height * 0.5f });
	m_shape.setPosition(position);
	m_shape.setFillColor(color);

	m_position = position;
}

void player::Player::set_score(int score)
{
	m_score = score;
}

sf::Vector2f player::Player::get_position()
{
	return m_position;
}

sf::RectangleShape& player::Player::get_shape()
{
	return m_shape;
}

sf::RectangleShape const& player::Player::get_shape() const
{
	return m_shape;
}

int player::Player::get_score()
{
	return m_score;
}

void player::Player::update_position()
{
	m_position += (m_direction) * static_cast<float>(m_speed);
	m_shape.setPosition(m_position);
}