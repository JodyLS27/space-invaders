#pragma once
#include <SFML/Graphics.hpp>
#include <String>

// TODO: Remove Chrono from this header file.
// TODO: Set Default Values on all Member variables
#include <chrono>

namespace player
{
class Player
{

public:
	Player(uint16_t score, float speed, uint16_t width = 25, uint16_t height = 25);

	uint16_t get_score() const;
	uint16_t get_width() const;
	uint16_t get_height() const;
	sf::Vector2f const& get_position() const;
	sf::RectangleShape const& get_shape() const;
	sf::RectangleShape& get_shape();

	void set_position(const sf::Vector2f& position);
	void set_direction();
	void set_shape(sf::Color color = sf::Color::Red);

	void set_move_up(bool state);
	void set_move_left(bool state);
	void set_move_right(bool state);
	void set_move_down(bool state);

	/////////////////////////////////////////////////////////
	/// This function checks weather a players direction can be changed based
	/// on the current key being pressed an or any alternative keyes being 
	/// pressed at the same time.
	/// 
	/// @param direction_to: String parameter of the direction to change to.
	/// 
	/// @return Type: Bool
	/////////////////////////////////////////////////////////
	bool can_change_direction(std::string direction_to);
	void increment_score();
	void update_position(sf::Vector2f position);

	sf::Vector2f window_collision(const sf::Vector2u window_size, const std::chrono::milliseconds& delta_time);

private:

	sf::RectangleShape m_shape{};
	sf::Vector2f m_direction{ 0.0f, 0.0f };

	float m_speed{ 0.0f };
	uint16_t m_score{ 0 };
	uint16_t m_width{ 25 };
	uint16_t m_height{ 25 };

	// TODO: Change to Enum
	bool m_move_up{ false };
	bool m_move_down{ false };
	bool m_move_left{ false };
	bool m_move_right{ false };

	// TODO: Add Enum for move up and down
};
}