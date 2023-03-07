#include <player.hpp>


player::Player::Player(int score, int speed, int width, int height)
	: m_score(score), m_speed(speed), m_width(width), m_height(height)
{}
// PRIVATE FUNCTIONS


// PUBLIC FUNCTIONS
void player::Player::set_position(sf::Vector2f position)
{
	m_position = position;
}

void player::Player::set_direction()
{
	m_direction = { 0.0f, 0.0f };
	if (m_move_up) { m_direction = { 0.0f, -1.0f }; }
	else if (m_move_left) { m_direction = { -1.0f, 0.0f }; }
	else if (m_move_down) { m_direction = { 0.0f, 1.0f }; }
	else if (m_move_right) { m_direction = { 1.0f , 0.0f }; }
}

void player::Player::set_shape(sf::Color color)
{
	m_shape.setSize({ static_cast<float>(m_width), static_cast<float>(m_height) });
	m_shape.setOrigin({ m_width * 0.5f, m_height * 0.5f });
	m_shape.setPosition(m_position);
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

void player::Player::increment_score()
{
	++m_score;
}

sf::Vector2f player::Player::get_position() const
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

int player::Player::get_score() const
{
	return m_score;
}

int player::Player::get_width() const
{
	return m_width;
}

int player::Player::get_height() const
{
	return m_height;
}

void player::Player::event_handler(sf::Event event)
{
	/// <summary>
	/// This function handles the player keyboard inputs and sets which way the player will move next.
	/// </summary>
	/// <param event></param>

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) { m_move_up = true; }
		if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) { m_move_left = true; }
		if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) { m_move_down = true; }
		if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) { m_move_right = true; }
	}

	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) { m_move_up = false; }
		if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) { m_move_left = false; }
		if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) { m_move_down = false; }
		if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) { m_move_right = false; }
	}
}

void player::Player::update_position(sf::Vector2f position)
{
	m_position = position;
	m_shape.setPosition(position);
}

void player::Player::update_position(float delta_time)
{
	m_position += (m_direction * delta_time) * m_speed;
	m_shape.setPosition(m_position);
}

// Set the position the player is going to be and then check if it hits the 
// window and adjust the positioning.
sf::Vector2f player::Player::window_collision(const sf::Vector2u window_size,
	float delta_time)
{
	sf::Vector2f ret_position = m_position + (m_direction * delta_time) * m_speed;

	if (ret_position.x < (m_width * 0.5f)) { ret_position.x = (m_width * 0.5f); }
	if (ret_position.x > (window_size.x - (m_width * 0.5f))) { ret_position.x = (window_size.x - (m_width * 0.5f)); }
	if (ret_position.y < (m_height * 0.5f)) { ret_position.y = (m_height * 0.5f); }
	if (ret_position.y > (window_size.y - (m_height * 0.5f))) { ret_position.y = (window_size.y - (m_height * 0.5f)); }

	return ret_position;
}