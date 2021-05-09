#pragma once
#include <vector>
#include "Scene.h"
class SceneManager
{
private:
	int currentSceneIndex;
	std::vector <Scene*> scenes;

public:
	SceneManager();
	~SceneManager();

	void Loadscene(int sceneIndex);
	void Addscene(Scene* scene);
	void Removescene(int sceneIndex);
	void Load();
	void Update();
	void Render(sf::RenderWindow& window);


	inline const int& GetActiveScene() { return currentSceneIndex;}
};

