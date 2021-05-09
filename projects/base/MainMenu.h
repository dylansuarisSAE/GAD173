#pragma once
#include "Scene.h"

class MainMenu : public  Scene
{
public:
	MainMenu();
	~MainMenu();


	void init() override;
	void Load() override;
	void update() override;
	void Render(sf::RenderWindow& window) override;
};

