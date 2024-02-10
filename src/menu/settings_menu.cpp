#include "menu/settings_menu.hpp"

menu::SettingsMenu::SettingsMenu()
{
	std::cout << "\nMain menu Constructor() called\n";
}

menu::SettingsMenu::~SettingsMenu()
{
	std::cout << "Main menu ~Destructor() called\n";
}

void menu::SettingsMenu::init()
{
	// TODO: Test when this will Fire
	// TODO: Initialize the window and menu systems
	std::cout << "Main menu init() called\n";
}

void menu::SettingsMenu::update(menu::MenuManager& menu_manager)
{
	// TODO: Check if the user is Moving up or down in the menu
	std::cout << "Main menu update() called\n";

	if (menu_manager.get_current_option() != menu_manager.get_next_option())
	{
		if (menu_manager.get_next_option() == 1)
			menu_manager.switch_menu(std::make_unique<menu::MainMenu>());
	}
}

void menu::SettingsMenu::draw()
{
	// TODO: Draw the textures as needed.
	std::cout << "Main menu draw() called\n";
}