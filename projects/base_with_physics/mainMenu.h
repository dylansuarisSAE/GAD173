#pragma once
#include "ScenE.h"

class mainMenu : public  ScenE
{
public:
	mainMenu();
	~mainMenu();


	void init() override;
	void Load() override;
	void update() override;
	void Render(sf::RenderWindow& window) override;
};

