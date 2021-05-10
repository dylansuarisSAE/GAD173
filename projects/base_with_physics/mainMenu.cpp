#include "mainMenu.h"


mainMenu::mainMenu()
{
}

mainMenu::~mainMenu()
{
}

void mainMenu::init()
{
}

void mainMenu::Load()
{
	ScenE::Load();
}

void mainMenu::update()
{
	ScenE::update();
}

void mainMenu::Render(sf::RenderWindow& window)
{
	ScenE::Render(window);

	//std::cout << "mainMenu rendered " << std::endl;
}
