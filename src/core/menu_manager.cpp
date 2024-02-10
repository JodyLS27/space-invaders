#include "core/menu_manager.hpp"

menu::MenuManager::MenuManager()
{
	std::cout << "\nMenu Manager Constructor() called\n";
}

menu::MenuManager::~MenuManager()
{
	std::cout << "\nMenu Manager ~Destructor() called\n";
}

void menu::MenuManager::init()
{
	// TODO: Set the current state to be main_menu on first load
	// TODO: call the main menu init() function

	// store the main menu object
	current_menu = std::make_unique<menu::MainMenu>();
	current_menu->init();
}

void menu::MenuManager::update()
{
	// TODO: Run the update of the current state.
	current_menu->update(*this);
}

void menu::MenuManager::set_current_option(int16_t current_option)
{
	m_current_option = current_option;
}

void menu::MenuManager::set_next_option(int16_t next_option)
{
	m_next_option = next_option;
}

int16_t menu::MenuManager::get_current_option()
{
	return m_current_option;
}

int16_t menu::MenuManager::get_next_option()
{
	return m_next_option;
}

// TODO: Implement the Menu swithcin
void menu::MenuManager::switch_menu(std::unique_ptr<menu::Menu> new_menu)
{
	current_menu = std::move(new_menu);
	current_menu->init();
}
