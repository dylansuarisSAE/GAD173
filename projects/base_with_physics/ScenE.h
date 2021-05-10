#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"


class ScenE
{
private:
	bool isRunning;
	bool isLoaded;


public:
	ScenE();
	~ScenE();

	virtual void init();
	virtual void Load();
	virtual void update();
	virtual void Render(sf::RenderWindow& window);

	inline bool IsLoaded() { return isLoaded; }
};


