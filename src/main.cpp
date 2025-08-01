#include "core/game_manager.hpp"
#include "main.h"

int main()
{
	game_manager::init();
	game_manager::start();

	game_manager::exit();
}