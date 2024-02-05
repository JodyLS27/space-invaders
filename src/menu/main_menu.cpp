#include "menu/main_menu.hpp"

menu::MainMenu::MainMenu()
{
	std::cout << "\n\tMain menu Constructor() called\n";
}

menu::MainMenu::~MainMenu()
{
	// TODO: Look into why the ~Destructor is not firing.
	std::cout << "\n\tMain menu ~Destructor() called\n";
}

void menu::MainMenu::init()
{
	// TODO: Test when this will Fire
	// TODO: Initialize the window and menu systems
	std::cout << "\tMain menu init() called\n";
}

void menu::MainMenu::update()
{
	// TODO: Check if the user is Moving up or down in the menu
	std::cout << "\tMain menu update() called\n";
}

void menu::MainMenu::draw()
{
	// TODO: Draw the textures as needed.
	std::cout << "\tMain menu draw() called\n";
}
