#pragma once
#include <vector>
#include "ScenE.h"
class SceneManage
{
private:
	int currentSceneIndex;
	std::vector <ScenE*> scenes;

public:
	SceneManage();
	~SceneManage();

	void Loadscene(int sceneIndex);
	void Addscene(ScenE* scene);
	void Removescene(int sceneIndex);
	void Load();
	void Update();
	void Render(sf::RenderWindow& window);


	inline const int& GetActiveScene() { return currentSceneIndex; }
};



