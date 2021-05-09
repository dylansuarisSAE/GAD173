#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SpriteAnimator.h"

class Scene
{
private:
	bool isRunning;
	bool isLoaded;


public:
	Scene();
	~Scene();

	virtual void init();
	virtual void Load();
	virtual void update();
	virtual void Render(sf::RenderWindow& window);

	inline bool IsLoaded() { return isLoaded; }
};

