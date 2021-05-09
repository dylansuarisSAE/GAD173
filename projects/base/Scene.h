#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Scene
{
public:
	bool IsRunning;
	bool IsLoaded;



	Scene();
	~Scene();

	virtual void init();
	virtual void Load();
	virtual void update();
	virtual void Render(sf::RenderWindow& window);

	inline bool IsLoaded() { return IsLoaded; }
};

