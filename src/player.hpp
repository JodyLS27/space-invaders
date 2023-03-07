#pragma once
#include <SFML/Graphics.hpp>

namespace player
{
	class Player
	{
	private:
		sf::Vector2f m_position{};
		sf::Vector2f m_direction{};
		sf::RectangleShape m_shape{};

		float m_speed{};
		int m_score{};
		int m_width{};
		int m_height{};

		bool m_move_up{ false };
		bool m_move_down{ false };
		bool m_move_left{ false };
		bool m_move_right{ false };

	public:
		Player(int score, int speed, int width = 25, int height = 25);

		void set_position(sf::Vector2f positio);
		void set_direction();
		void set_shape(sf::Color color = sf::Color::Red);
		void increment_score();

		sf::Vector2f get_position() const;
		sf::RectangleShape& get_shape();
		sf::RectangleShape const& get_shape() const;
		int get_score() const;
		int get_width() const;
		int get_height() const;

		void event_handler(sf::Event event);
		void update_position(float delta_time);
		void update_position(sf::Vector2f position);

		sf::Vector2f window_collision(const sf::Vector2u window_size, float delta_time);
	};
}