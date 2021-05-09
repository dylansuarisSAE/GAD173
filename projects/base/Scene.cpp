#include "Scene.h"

Scene::Scene():isRunning(false), isLoaded(false)
{
}

Scene::~Scene()
{
}

void Scene::init()
{
}

void Scene::Load()
{
	isRunning = true;
	isLoaded = true;
}

void Scene::update()
{
}

void Scene::Render(sf::RenderWindow& window)
{
}
