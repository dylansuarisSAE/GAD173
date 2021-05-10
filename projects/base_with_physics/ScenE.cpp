#include "ScenE.h"


ScenE::ScenE() :isRunning(false), isLoaded(false)
{
}

ScenE::~ScenE()
{
}

void ScenE::init()
{
}

void ScenE::Load()
{
	isRunning = true;
	isLoaded = true;
}

void ScenE::update()
{
}

void ScenE::Render(sf::RenderWindow& window)
{
}
