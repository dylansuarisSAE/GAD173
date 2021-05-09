#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Loadscene(int sceneIndex)
{
	if(!scenes[currentSceneIndex]->IsLoaded())
	currentSceneIndex = sceneIndex;
}

void SceneManager::Addscene(Scene* scene)
{
	scenes.push_back(scene);
}

void SceneManager::Removescene(int sceneIndex)
{
}

void SceneManager::Load()
{
	scenes[currentSceneIndex]->Load();
}

void SceneManager::Update()
{
	if (scenes.size() > 0) {
		scenes[currentSceneIndex]->update();
	}
}

void SceneManager::Render(sf::RenderWindow& window)
{
	if (scenes.size() > 0) {
		scenes[currentSceneIndex]->Render(window);
	}
}
