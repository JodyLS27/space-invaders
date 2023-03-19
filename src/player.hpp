#pragma once
#include <SFML/Graphics.hpp>

namespace player
{
	class Player
	{
	private:
		sf::Vector2f m_direction{};
		sf::RectangleShape m_shape{};

		float m_speed{};
		uint16_t m_score{};
		uint16_t m_width{};
		uint16_t m_height{};

		bool m_move_up{ false };
		bool m_move_down{ false };
		bool m_move_left{ false };
		bool m_move_right{ false };

		//sf::Vector2f get_center() const;

		// TODO: Look into returning m_shape.getPosition() and not having a private m_position variable.
		// This could allow for a more dynamic structure and we wont need to find the center each time.

		// TODO: Look into creating a player shape edge return ? Perhaps this should be in the 
		// Collision section ...? or another player class to extend player...?

	public:
		Player(uint16_t score, float speed, uint16_t width = 25, uint16_t height = 25);

		void set_position(const sf::Vector2f& position);
		void set_direction();
		void set_shape(sf::Color color = sf::Color::Red);
		void set_move_up(bool state);
		void set_move_left(bool state);
		void set_move_right(bool state);
		void set_move_down(bool state);


		void increment_score();

		sf::Vector2f const& get_position() const;
		sf::RectangleShape const& get_shape() const;
		sf::RectangleShape& get_shape();
		uint16_t get_score() const;
		uint16_t get_width() const;
		uint16_t get_height() const;


		void event_handler(sf::Event event);
		void update_position(sf::Vector2f position);
		/*void update_position(float delta_time);*/

		sf::Vector2f window_collision(const sf::Vector2u window_size, float delta_time);
	};
}