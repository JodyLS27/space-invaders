#include <player.hpp>

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

void player::Player::set_direction()
{
	// Diagonal Movement
	if (m_move_up && m_move_left)
	{
		m_direction = { -0.5f, -1.0f };
		return;
	}

	if (m_move_up && m_move_right)
	{
		m_direction = { 0.5f, -1.0f };
		return;
	}

	if (m_move_down && m_move_left)
	{
		m_direction = { -0.5f, 1.0f };
		return;
	}

	if (m_move_down && m_move_right)
	{
		m_direction = { 0.5f, 1.0f };
		return;
	}

	// Up, Down, Left, Right Movement
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

bool player::Player::can_change_direction(std::string direction_to)
{
	if (m_move_up && (direction_to == "left" || m_move_up && direction_to == "right"))
	{
		return true;
	}

	if (m_move_down && (direction_to == "left" || m_move_down && direction_to == "right"))
	{
		return true;
	}

	if ((m_move_left && direction_to == "up") || (m_move_left && direction_to == "down"))
	{
		return true;
	}

	if ((m_move_right && direction_to == "up") || (m_move_right && direction_to == "down"))
	{
		return true;
	}

	if (!m_move_up && !m_move_down && !m_move_left && !m_move_right)
	{
		return true;
	}

	return false;
}

void player::Player::increment_score()
{
	++m_score;
}

void player::Player::update_position(sf::Vector2f position)
{
	m_shape.setPosition(position);
}

// TODO: Move to Collision Class
sf::Vector2f player::Player::window_collision(const sf::Vector2u window_size,
											  const std::chrono::milliseconds& delta_time)
{
	sf::Vector2f ret_position{};

	float dt = std::chrono::duration_cast<std::chrono::duration<float>>(delta_time).count();

	ret_position = get_position() + (m_direction * dt) * m_speed;
	//ret_position.x = get_position().y + (m_direction.y * delta_time) * m_speed;

	if (ret_position.x < (m_width * 0.5f))
	{
		ret_position.x = (m_width * 0.5f);
	}

	if (ret_position.x > (window_size.x - (m_width * 0.5f)))
	{
		ret_position.x = (window_size.x - (m_width * 0.5f));
	}

	if (ret_position.y < (m_height * 0.5f))
	{
		ret_position.y = (m_height * 0.5f);
	}

	if (ret_position.y > (window_size.y - (m_height * 0.5f)))
	{
		ret_position.y = (window_size.y - (m_height * 0.5f));
	}

	return ret_position;
}

// PRIVATE FUNCTIONS