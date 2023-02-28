#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

#include <player.hpp>
#include <target.hpp>



void init(sf::Vector2u window_size, player::Player& player, target::Target& target)
{
	sf::Vector2f position = { static_cast<float>(window_size.x) * 0.5f, static_cast<float>(window_size.y) * 0.5f };

	player.set_position(position);
	player.set_shape(sf::Color::Green);

	target.set_position(target.generate_random_position(window_size));
	target.set_shape();
}

void logic(player::Player& player, target::Target& target, const sf::Event& event,
	const sf::Vector2u window_size, float delta_time)
{
	player.event_handler(event);
	player.set_direction();

	player.update_position(player.window_collision(window_size, delta_time));

	if (target.collision_hit(player.get_position(), player.get_width(), player.get_height()))
	{
		target.set_colour(sf::Color::Red);
	}
	else
	{
		target.set_colour(sf::Color::Red);
	}
}
void draw_text(sf::Font& font, sf::Text& text, int score)
{
	std::string data{ "Score: " + std::to_string(score) + "\n" };
	text.setFont(font);
	text.setString(data);
	text.setCharacterSize(18);
	text.setFillColor(sf::Color::White);
}

void render(sf::RenderWindow& window, sf::RectangleShape& player_shape, sf::CircleShape& target_shape, sf::Text& text)
{
	window.clear(sf::Color::Black);

	window.draw(player_shape);
	window.draw(target_shape);
	window.draw(text);
	window.display();
}

int main()
{
	player::Player player(0, 100.0f);
	target::Target target(15.0f);

	const sf::Vector2u window_size = sf::Vector2u{ 800, 600 };
	sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), "Move To Target");

	sf::Font font;
	sf::Text text;

	if (!font.loadFromFile("C:/Users/jodys/OneDrive/Documents/Fonts/Vogue.ttf"))
	{
		std::cout << "Error: Cannot load file." << std::endl;
	}

	using clock = std::chrono::steady_clock;
	using mil = std::chrono::milliseconds;
	using flt = std::chrono::duration<float>;

	auto end_clock = std::chrono::time_point_cast<mil>(clock::now());

	init(window_size, player, target);

	while (window.isOpen())
	{
		sf::Event event;

		auto current_clock = std::chrono::time_point_cast<mil>(clock::now());
		auto chrono_dt = current_clock - end_clock;
		end_clock = current_clock;

		float delta_time = std::chrono::duration_cast<flt>(chrono_dt).count();

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		logic(player, target, event, window_size, delta_time);

		draw_text(font, text, player.get_score());
		render(window, player.get_shape(), target.get_shape(), text);
	}

	return 0;
}

