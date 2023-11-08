#include <SFML/Graphics.hpp>

#include <chrono>
#include <unordered_map>

#include <player.hpp>
#include <target.hpp>
#include <logger.hpp>

// Storing key press and its held or not.
struct Input
{
	std::unordered_map<sf::Keyboard::Key, bool> held{};
};

void set_direction()
{

}

void init(sf::Vector2u window_size, player::Player& player, target::Target& target)
{
	sf::Vector2f position = { static_cast<float>(window_size.x) * 0.5f, static_cast<float>(window_size.y) * 0.5f };

	player.set_position(position);
	player.set_shape(sf::Color::Green);

	target.set_position(target.generate_random_position(window_size));
	target.set_shape();
}

void event_handling(sf::RenderWindow& window, sf::Event& event, player::Player& player, Input& input)
{
	while (window.pollEvent(event))
	{
		bool is_pressed{};

		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::KeyPressed:
			is_pressed = true;
			break;

		case sf::Event::KeyReleased:
			is_pressed = false;
			break;

		default:
			return;

			// Pass through key code and its value.
			input.held[event.key.code] = is_pressed;
		}
	}
}

void logic(player::Player& player, target::Target& target,
		   const sf::Vector2u window_size,
		   std::chrono::milliseconds delta_time, Input input)
{
	set_direction();


	player.update_position(player.window_collision(window_size, delta_time));

	if (target.collision_hit(player.get_position(), player.get_width(), player.get_height()))
	{
		target.set_position(target.generate_random_position(window_size));

		player.increment_score();
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
	// Initiate classes
	player::Player player{ 0, 100.0f };
	target::Target target{ 15.0f };

	// Initialize struct
	Input input{};

	// Setup window
	const sf::Vector2u window_size = sf::Vector2u{ 800, 600 };
	sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), "Move To Target");

	window.setKeyRepeatEnabled(false);

	// TODO: Move fonts to Seperate Class.
	sf::Font font;
	sf::Text text;

	if (!font.loadFromFile("../../../fonts/batmfa__.ttf"))
	{
		std::cout << "Error: Cannot load file. \n";
	}

	using clock = std::chrono::steady_clock;
	using mil = std::chrono::milliseconds;

	auto end_clock = std::chrono::time_point_cast<mil>(clock::now());

	init(window_size, player, target);

	while (window.isOpen())
	{
		sf::Event event;

		auto current_clock = std::chrono::time_point_cast<mil>(clock::now());
		auto delta_time = current_clock - end_clock;
		end_clock = current_clock;

		// Player input.
		event_handling(window, event, player, input);

		logic(player, target, window_size, delta_time, input);

		draw_text(font, text, player.get_score());
		render(window, player.get_shape(), target.get_shape(), text);
	}

	return 0;
}
