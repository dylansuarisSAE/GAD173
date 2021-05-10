#include "SceneManage.h"
#include "ScenE.h"

SceneManage::SceneManage()
{
}

SceneManage::~SceneManage()
{
}

void SceneManage::Loadscene(int sceneIndex)
{
	// if (!scenes[currentSceneIndex]->IsLoaded())
		currentSceneIndex = sceneIndex;
}

void SceneManage::Addscene(ScenE* scene)
{
	scenes.push_back(scene);
}

void SceneManage::Removescene(int sceneIndex)
{
}

void SceneManage::Load()
{
	scenes[currentSceneIndex]->Load();
}

void SceneManage::Update()
{
	if (scenes.size() > 0) {
		scenes[currentSceneIndex]->update();
	}
}

void SceneManage::Render(sf::RenderWindow& window)
{
	if (scenes.size() > 0) {
		scenes[currentSceneIndex]->Render(window);
	}
}