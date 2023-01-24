#include <SFML/Graphics.hpp>

#include <player.hpp>


void init(sf::Vector2u window_size, player::Player& player)
{
	sf::Vector2f position = { static_cast<float>(window_size.x) * 0.5f, static_cast<float>(window_size.y) * 0.5f };
	player.set_shape(position, sf::Color::Green);
}

void logic()
{

}

void event_handler(player::Player& player, sf::Keyboard::Key key)
{
	player.set_direction(key);
	player.update_position();
}

void render(sf::RenderWindow& window, sf::RectangleShape player_shape)
{
	window.clear(sf::Color::Black);

	window.draw(player_shape);
	window.display();
}


int main()
{
	player::Player player(0, 10);

	const sf::Vector2u window_size = sf::Vector2u{ 800, 600 };
	sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), "Move To Target");

	init(window_size, player);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				event_handler(player, event.key.code);
				break;

			default:
				break;
			}
		}

		render(window, player.get_shape());
	}

	return 0;
}

