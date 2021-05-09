#pragma once
#include "Scene.h"

class LevelOne : public Scene
{
public:
	LevelOne();
	~LevelOne();


	void init() override;
	void Load() override;
	void update() override;
	void Render(sf::RenderWindow& window) override;
};

