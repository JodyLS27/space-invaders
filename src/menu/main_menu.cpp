#include "menu/main_menu.hpp"

menu::MainMenu::MainMenu()
{
	std::cout << "\nMain menu Constructor() called\n";
}

menu::MainMenu::~MainMenu()
{
	std::cout << "Main menu ~Destructor() called\n";
}

void menu::MainMenu::init()
{
	// TODO: Test when this will Fire
	// TODO: Initialize the window and menu systems
	std::cout << "Main menu init() called\n";
}

void menu::MainMenu::update()
{
	// TODO: Check if the user is Moving up or down in the menu

	if (menu_manager.get_current_option() != menu_manager.get_next_option())
	{
		if (menu_manager.get_next_option() == 2)
			menu_manager.switch_menu(std::make_unique<menu::SettingsMenu>());
	}
}

void menu::MainMenu::draw()
{
	std::cout << "Main menu draw() called\n";

	// Draw the menu screen
	std::cout << "choose a menu item\n";
	std::cout << "1. Play Game\n";
	std::cout << "2. Sttings\n";
	std::cout << "3. Exit\n\n";
}
