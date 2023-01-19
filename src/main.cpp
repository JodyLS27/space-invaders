#include <SFML/Graphics.hpp>


void init()
{

}

void render()
{

}

void logic()
{

}

void event_handler()
{

}

void player_input(sf::Keyboard::Key key)
{

}


int main()
{
	const sf::Vector2u window_size = sf::Vector2u{ 800, 600 };
	sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), "Move To Target");

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
				player_input(event.key.code);
				break;
			default:
				break;
			}
		}

		// Must clear the window before continuing.
		window.clear(sf::Color::Black);

		// Update Positions here

		// Render Logic Here

		// Window.draw() here

		window.display();

	}

	return 0;
}

