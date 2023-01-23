#include <SFML/Graphics.hpp>

#include <player.hpp>
#include <chrono>

void init(sf::Vector2u window_size, player::Player& player)
{
	player.set_shape(window_size, { 25.0f, 25.0f });
}

void render(sf::RenderWindow& window, sf::RectangleShape player_shape)
{
	window.clear(sf::Color::Black);

	window.draw(player_shape);
	window.display();
}

void logic()
{

}

void event_handler()
{

}


int main()
{
	player::Player player;
	int score{};

	const sf::Vector2u window_size = sf::Vector2u{ 800, 600 };
	sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), "Move To Target");

	init(window_size, player);
	
	using clock = std::chrono::steady_clock;
	using mili = std::chrono::milliseconds;

	auto end_clock = std::chrono::time_point_cast<mili>(clock::now());

	while (window.isOpen())
	{
		sf::Event event;

		// create delta time
		auto current_clock = std::chrono::time_point_cast<mili>(clock::now());
		auto dt = current_clock - end_clock;
		end_clock = current_clock;

		float delta_time = std::chrono::duration_cast<std::chrono::duration<float>>(dt).count();

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				player.set_direction(event.key.code, delta_time);
				break;

			default:
				break;
			}
		}

		render(window, player.get_shape());
	}

	return 0;
}

