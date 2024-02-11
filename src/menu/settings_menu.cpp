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
	// TODO: Test when this will Fire
	// TODO: Initialize the window and menu systems
	std::cout << "Settings init() called\n";
}

void menu::SettingsMenu::update(MenuManager& menu_manager)
{
	// TODO: Check if the user is Moving up or down in the menu
	std::cout << "Settings menu update() called\n";
	std::cout << "\nSettings Menu - Current Option: " << menu_manager.get_current_option() << "\n";
	std::cout << "Settings Menu - Next Option: " << menu_manager.get_current_option() << "\n\n";

	if (menu_manager.get_current_option() != menu_manager.get_next_option())
	{
		if (menu_manager.get_next_option() == 1)
			menu_manager.switch_menu(std::make_unique<menu::MainMenu>());
	}
}

void menu::SettingsMenu::draw()
{
	// TODO: Draw the textures as needed.
	std::cout << "Settings menu draw() called\n";
}