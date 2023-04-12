#include <player.hpp>
#include <String>

#include <windows.h>
#include <format>

player::Player::Player(uint16_t score, float speed, uint16_t width, uint16_t height)
	: m_score(score), m_speed(speed), m_width(width), m_height(height)
{}

// PUBLIC FUNCTIONS

uint16_t player::Player::get_score() const
{
	return m_score;
}

uint16_t player::Player::get_width() const
{
	return m_width;
}

uint16_t player::Player::get_height() const
{
	return m_height;
}

sf::Vector2f const& player::Player::get_position() const
{
	return m_shape.getPosition();
}

sf::RectangleShape& player::Player::get_shape()
{
	return m_shape;
}

sf::RectangleShape const& player::Player::get_shape() const
{
	return m_shape;
}

void player::Player::set_position(const sf::Vector2f& position)
{
	m_shape.setPosition(position);
}

/* TODO: Look into can_move() function perhaps.
* - we need to have checks that nothing is already down. if it is,
move on otherwise check whats pressed and set it to true.
*/

void player::Player::set_direction()
{
	std::string msg = std::format("Up: {} | Down : {} | Left : {} | Right : {} \n\n", m_move_up, m_move_down, m_move_left, m_move_right);
	OutputDebugStringA(msg.c_str());

	if (m_move_up)
	{
		m_direction = { 0.0f, -1.0f };
		return;
	}

	if (m_move_left)
	{
		m_direction = { -1.0f, 0.0f };
		return;
	}

	if (m_move_down)
	{
		m_direction = { 0.0f, 1.0f };
		return;
	}

	if (m_move_right)
	{
		m_direction = { 1.0f , 0.0f };
		return;
	}

	m_direction = { 0.0f , 0.0f };
}

void player::Player::set_shape(sf::Color color)
{
	m_shape.setSize({ static_cast<float>(m_width), static_cast<float>(m_height) });
	m_shape.setOrigin({ m_width * 0.5f, m_height * 0.5f });
	m_shape.setFillColor(color);
}

void player::Player::set_move_up(bool state)
{
	m_move_up = state;
}

void player::Player::set_move_left(bool state)
{
	m_move_left = state;
}

void player::Player::set_move_right(bool state)
{
	m_move_right = state;
}

void player::Player::set_move_down(bool state)
{
	m_move_down = state;
}

bool player::Player::can_change_direction()
{
	// TODO Implement directional Check but keep smooth movement.
	if (m_move_up && m_move_left)
	{
		
	}
	/*if (m_move_up || m_move_left || m_move_down || m_move_right)
	{
		return false;
	}*/

	return true;
}

void player::Player::increment_score()
{
	++m_score;
}

void player::Player::update_position(sf::Vector2f position)
{
	m_shape.setPosition(position);
}

// Set the position the player is going to be and then check if it hit's the 
// window and adjust the positioning.
// TODO: Move to Collision Class
sf::Vector2f player::Player::window_collision(const sf::Vector2u window_size,
											  float delta_time)
{
	sf::Vector2f ret_position = get_position() + (m_direction * delta_time) * m_speed;

	if (ret_position.x < (m_width * 0.5f)) { ret_position.x = (m_width * 0.5f); }
	if (ret_position.x > (window_size.x - (m_width * 0.5f))) { ret_position.x = (window_size.x - (m_width * 0.5f)); }
	if (ret_position.y < (m_height * 0.5f)) { ret_position.y = (m_height * 0.5f); }
	if (ret_position.y > (window_size.y - (m_height * 0.5f))) { ret_position.y = (window_size.y - (m_height * 0.5f)); }

	return ret_position;
}

// PRIVATE FUNCTIONS