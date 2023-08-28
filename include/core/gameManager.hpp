#pragma once

namespace gameManager
{
class GameManager
{
public:
	// Attributes

	// Functions
	void run();

private:
	void init();
	void createController();
	void update();
};
}