#pragma once

#include <memory>
#include <iostream>

#include "menu/i_menu.hpp"
#include "menu/i_menu_switcher.hpp"
#include "menu/main_menu.hpp"

namespace menu
{
	class MenuController : public IMenuSwitcher
	{
	public:
		MenuController();
		~MenuController();

		/**
		* Set the current menu option
		*
		* @note: This holds a number for now just for Testing and will be updated later on
		* to another system
		*
		* @param current_option: Stores an int16_t of the current selction
		**/
		void set_current_option(int16_t current_option);

		/**
		* Set the Next menu option
		*
		* @note: This holds a number for now just for Testing and will be updated later on
		* to another system
		*
		* @param next_option: Stores an int16_t of the next selction
		**/
		void set_next_option(int16_t next_option);

		/**
		* Get the current menu option
		*
		* @note: This holds a number for now just for Testing and will be updated later on
		* to another system
		**/
		const int16_t get_current_option();

		/**
		* Get the next menu option
		*
		* @note: This holds a number for now just for Testing and will be updated later on
		* to another system
		**/
		const int16_t get_next_option();

		/**
		* Initialize the menu controller.
		*
		* The function is going to set the default menu option on game first load
		**/
		void init(); // TODO: Call the current state set_context() Function to pass in this context ref

		/**
		* Update the menus each frame
		*
		* This function is designed to run the current menu object's update function
		**/
		void update();

		/**
		* Draw the menu to the screen
		*
		* This function is used to render the current menu options to the screen
		**/
		void draw();

		/**
		* Used to change menus of type IMenu.
		*
		* This function is used to switch to a new menu of type IMenu.
		* @note: It is inherited from i_menu_switcher
		*
		* @param new_menu: is a unique_ptr of type IMenu
		**/
		void switch_menu(std::unique_ptr<IMenu> new_menu) final;

		// Pointer for the next menu to load
		std::unique_ptr<IMenu> m_next_menu;

	protected:
		/**
		* The current menu in use
		*
		* This is a unique pointer that holds one menu object at a time.		*
		**/
		std::unique_ptr<IMenu> m_current_menu;

	private:
		int16_t m_current_option{};
		int16_t m_next_option{};
	};
}