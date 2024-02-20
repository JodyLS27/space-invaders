#include "core/menu_manager.hpp"

menu::MenuManager::MenuManager()
{
	std::cout << "\nMenu Manager Constructor() called\n";
}

menu::MenuManager::~MenuManager()
{
	std::cout << "\nMenu Manager ~Destructor() called\n";
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

void menu::MenuManager::init()
{
	// store the MainMenu object and call init function
	current_menu = std::make_unique<menu::MainMenu>();
	current_menu->init();
}

void menu::MenuManager::update()
{
	// TODO: Check to see if m_next_menu is set, then switch to that menu
	current_menu->update(*this);
}


void menu::MenuManager::draw()
{
	current_menu->draw();
}


void menu::MenuManager::switch_menu(std::unique_ptr<menu::IMenu> new_menu)
{
	// TODO: Set m_next_menu here
	current_menu = std::move(new_menu);
	current_menu->init();
}
