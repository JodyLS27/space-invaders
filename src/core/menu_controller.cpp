#include "core/menu_controller.hpp"

menu::MenuController::MenuController()
{
	std::cout << "\nMenu Manager Constructor() called\n";
}

menu::MenuController::~MenuController()
{
	std::cout << "\nMenu Manager ~Destructor() called\n";
}

void menu::MenuController::set_current_option(int16_t current_option)
{
	m_current_option = current_option;
}

void menu::MenuController::set_next_option(int16_t next_option)
{
	m_next_option = next_option;
}

const int16_t menu::MenuController::get_current_option()
{
	return m_current_option;
}

const int16_t menu::MenuController::get_next_option()
{
	return m_next_option;
}

void menu::MenuController::init()
{
	// Set the current menu to be `MainMenu`
	m_current_menu = std::make_unique<menu::MainMenu>();
	m_current_menu->init();
}

void menu::MenuController::update()
{
	// TODO: Check to see if m_next_menu is set, then switch to that menu
	m_current_menu->update();
}


void menu::MenuController::draw()
{
	m_current_menu->draw();
}


void menu::MenuController::switch_menu(std::unique_ptr<menu::IMenu> new_menu)
{
	// TODO: Set m_next_menu here
	m_current_menu = std::move(new_menu);
	m_current_menu->init();
}
