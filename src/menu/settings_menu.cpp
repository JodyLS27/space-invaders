#include "menu/settings_menu.hpp"

menu::SettingsMenu::SettingsMenu()
{
	std::cout << "\nSettings menu Constructor() called\n";
}

menu::SettingsMenu::~SettingsMenu()
{
	std::cout << "Settings menu ~Destructor() called\n";
}

void menu::SettingsMenu::init()
{
	// TODO: Initialize the window and menu systems
	std::cout << "Settings init() called\n";
}

void menu::SettingsMenu::update()
{
	// TODO: Check if the user is Moving up or down in the menu

	if (menu_manager.get_current_option() != menu_manager.get_next_option())
	{
		if (menu_manager.get_next_option() == 1)
			menu_manager.switch_menu(std::make_unique<menu::MainMenu>());
	}
}

void menu::SettingsMenu::draw()
{
	// TODO: Draw the textures as needed.
	std::cout << "Settings menu draw() called\n\n";

	// Draw the menu screen
	std::cout << "1. Dificulty: Checking...\n";
	std::cout << "2. Screen Resolution: Console Window for now\n";
	std::cout << "3. Graphics Settings: Nothing here yet\n";
	std::cout << "4. Back\n\n";
}